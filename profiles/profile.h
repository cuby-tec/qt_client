#ifndef PROFILE_H
#define PROFILE_H


/**
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <errno.h>
*/

#include <../../../../../usr/include/stdio.h>
#include <../../../../../usr/include/stdlib.h>
#include <../../../../../usr/include/ctype.h>
#include <../../../../../usr/include/math.h>
#include <../../../../../usr/include/errno.h>

#include <QWidget>
#include <QTabWidget>
#include <QComboBox>
#include <QJsonArray>
#include <QJsonParseError>

//#include "profiles/profiledialog.h"

#include "links/json_sintax.h"
#include "links/parson.h"
#include <string>

//---------- defs

#define PRFL_NAMES_NUMBER		10
#define PRFL_NAME_SIZE			128
#define PRFL_DESCRIPTION_SIZE	1024


typedef struct _prfl_StringArray_t prfl_StringArray;
typedef  struct _prfl_String_t	prfl_String;

struct _prfl_String_t{
    size_t isDefault;	// признак текущего профиля.
    size_t length;	// длина строки.
    char string[PRFL_NAME_SIZE];
};


struct _prfl_StringArray_t{
    size_t index;	// текущее количество элементов.
    size_t length;	// максимальное количество элементов.
    prfl_String data[PRFL_NAMES_NUMBER];	// указатель на буфер данных.

};

//-- var


//------------- function
class Profile
{
public:
    Profile();

    bool loadProfile();

    /**
     * Создать переменные и загрузить файл Профилей.
     * Проверка наличия файла профиля и его правильность или
     * создать новый профиль профиль по-умолчанию.
     */
    bool init_profile();

    void Profiles_increment(int idx);

    QString getProfileName(int index);

    int getProfileNameCount() { return (profileNamesArray.count()); }

    QString getProfileDescription(int index);

    QString getProfileFileName(int index);

    bool isDefaultProfile(int index);

//----------- Generic

    QString getX_STEPS();

    QString getY_STEPS();

    QString getZ_STEPS();

    QString getX_MAX_RATE();

    QString get_TEMPERATURE();

    QString get_INTEGRAL();

    QString get_PROPTIONAL();

    QString get_DERIVATIVE();

    void  set_TEMPERATURE(QString num);
    void  set_INTEGRAL(QString num);
    void  set_PROPTIONAL(QString num);
    void  set_DERIVATIVE(QString num);

    void saveProfileDocument();

private:

    QWidget *profPage;// pfofile page

    const char* pprofile_file_name;// = "profiles.json";	// Список профилей

    void _fill_prfl_names(JSON_Array* array);

    size_t prfl_add_element(prfl_StringArray* array, char* name,size_t isdefs);

    char*  _dotnamebuffer(const char *root, const char* name);

    QJsonDocument loadDocument(QString filename);

    QString readFile(const QString &filename);

    void writeObject(QJsonObject &json, QString key, QJsonObject newobj);

//--------- vars

    QJsonArray profileNamesArray;   // Список профилей

//    QComboBox *profiles;

    QString profile_filename;

    QJsonDocument profile_doc; // Документ текущего профиля.

    QJsonParseError parseError;

    int profileIndex;


};

#endif // PROFILE_H