#include "gconsole.h"

#include <string.h>

#include <QDebug>

#include "gparcer/ghelper.h"
#include "gparcer/gParcer.h"


GConsole::GConsole(QObject *parent) : QObject(parent)
{

}


GConsole::GConsole(Ui::MainWindow* &ui)
{
    this->uia = ui;
    oldBlockNumber = -1;
}



/**
 * Разбор одной строки.
 * @brief GcodeWorker::parceString
 * @param src
 * @return
 */
sGcode*
GConsole::parceString(char* src,int* error)
{
    sGcode* result = NULL;

    int state;
//    int error;
    initGparcer();
    clear_sgcode();
    //------------------------- begen parcing

    state = scanner();
    if(state == 4){
        strcpy(fsm.buf+fsm.have,src);

        fsm.lenfile = strlen(src);

        state = scanner();

        if(sgcode.line != 0){
//            clear_sgcode();

            result = &sgcode;
        }

        *error = fsm.cs;

    }
    return result;
}



/**
 * Формиирование команда для немедленного выполнения.
 * @brief GConsole::on_pushButton_linestep_clicked
 */
void
GConsole::on_pushButton_linestep_clicked()
{

    const QString error1("ERROR: Command dosn't accepted.");
    const QString error2("Command accepted.");
    const QString msg1("accepted:");

    int parce_error;
    sGcode* sgcode;

     QColor bkgColor(170, 255, 255);
    int bnumber = uia->textEdit_command->textCursor().block().blockNumber();


    qDebug()<<"GConsole[60] Clicked line:"<<bnumber ;

    char cmdbuffer[80];
    char* pbuffer;
    size_t size = sizeof(cmdbuffer);
    size_t len;

    QString block =  uia->textEdit_command->textCursor().block().text();

    std::string cmdstd = block.toStdString();
    pbuffer = strncpy( cmdbuffer,cmdstd.data(),size );

    len = strlen(pbuffer);

    *(pbuffer+len) = 0x0A;

//    uia->label_commandLine->setText(uia->textEdit_command->document()->findBlockByLineNumber(bnumber).text());
    uia->label_commandLine->setText(pbuffer);
// -------- parcer

    sgcode = parceString(pbuffer, &parce_error);
    if( sgcode != 0 && sgcode->group != ' ')
    {
//        uia->label_commandLine->setText(QString(error2)+QString("%1").arg(parce_error) );
        uia->label_commandLine->setText(msg1+ QString(sgcode->group)+QString(sgcode->value) );

    }else{
        uia->label_commandLine->setText(QString(error1)+QString("%1").arg(parce_error) );
    }

//--------- parcer end

}

void
GConsole::on_textEdit_command_cursorPositionChanged()
{
    int bnumber = uia->textEdit_command->textCursor().block().blockNumber();

    QColor bkgColor(170, 255, 255);

//    QTextFormat format = ui->textEdit_command->textCursor().block().blockFormat();
    QString str = uia->textEdit_command->textCursor().block().text();
//    uia->label_commandLine->setText(str + QString("%1").arg(bnumber));
//    ui->textEdit_command->textCursor().block().blockFormat().setBackground(QBrush(QColor(120,120,120)));

    QTextBlock block =  uia->textEdit_command->textCursor().block();
    QTextCursor cursor(block);

    QTextBlockFormat blockFormat = cursor.blockFormat();
    blockFormat.setBackground(QColor(Qt::yellow));
    cursor.setBlockFormat(blockFormat);

    QTextBlock prevBlock = block.previous();
    if(prevBlock.length()>0){
        QTextCursor cu1(prevBlock);
        QTextBlockFormat blockFprev = cu1.blockFormat();
        blockFprev.setBackground(bkgColor);
        cu1.setBlockFormat(blockFprev);
    }

    QTextBlock nextBlock = block.next();
    if(nextBlock.length() > 0)
    {
        QTextCursor cuNext(nextBlock);
        QTextBlockFormat blockNextFormat = cuNext.blockFormat();
        blockNextFormat.setBackground(bkgColor );
        cuNext.setBlockFormat(blockNextFormat);
    }

    if(oldBlockNumber>=0 && oldBlockNumber!= bnumber){
        QTextBlock oldBlock = uia->textEdit_command->document()->findBlockByLineNumber(oldBlockNumber);
        QTextCursor cuOld(oldBlock);
        QTextBlockFormat blockOldNextFormat = cuOld.blockFormat();
        blockOldNextFormat.setBackground(bkgColor );
        cuOld.setBlockFormat(blockOldNextFormat);

    }

    qDebug()<< "GConsole[107] old:"<< oldBlockNumber<<" now:"<< bnumber;
    oldBlockNumber = bnumber;

}
