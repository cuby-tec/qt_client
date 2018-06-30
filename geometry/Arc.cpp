/*
 * Arc.cpp
 *
 *  Created on: 28.06.2018
 *      Author: walery
 */


#include "Arc.h"
#include <QtGlobal>
#include "mLine.h"

Arc::Arc() {
	// TODO Auto-generated constructor stub
	this->radious = qQNaN();
	this->precicion = qQNaN();
	this->points_number = NULL;
	clockWise = true;
}

Arc::~Arc() {
	// TODO Auto-generated destructor stub
}

void
Arc::setStart(QString x, QString y)
{
	bool ok;

    x.replace(',','.');

	start.x = x.toDouble(&ok);
	Q_ASSERT(ok);

    y.replace(',','.');
	start.y = y.toDouble(&ok);
	Q_ASSERT(ok);
}

void
Arc::setEnd(QString x, QString y)
{
	bool ok;
	end.x = x.toDouble(&ok);
	Q_ASSERT(ok);

	end.y = y.toDouble(&ok);
	Q_ASSERT(ok);
}

void
Arc::setCenter(QString x, QString y) {
	bool ok;

	center.x = x.toDouble(&ok);
	Q_ASSERT(ok);

	center.y = y.toDouble(&ok);
	Q_ASSERT(ok);

    mLine* line = new mLine();

	this->radious = line->getLength();

}

void Arc::setRadious(QString r) {
	bool ok;

	radious = r.toDouble(&ok);

	Q_ASSERT(ok);
}

void Arc::calculateRadious() {

	radious = sqrt(pow((start.x-end.x),2.0)+pow((start.y - end.y),2.0));

	calculateAngle();

}

Point Arc::getPoint(size_t number) {
// TODOH Arc::getPoint


}

void
Arc::setPrecicion(QString pstr)
{
	bool ok;
    QString tstr = pstr.replace(',','.');

    double_t precicion = tstr.toDouble(&ok);
	Q_ASSERT(ok);

	setPrecicion(precicion);
}


void
Arc::setPrecicion(double_t precicion) {

	this->precicion = precicion;

}

void Arc::calculateAngle() {

    Q_ASSERT((radious != qQNaN()) && (radious != 0) );

	// Угол сегмента
	alfa = 2.0 * asin(precicion/(radious*2.0));

	//=SQRT(SUMSQ(B3-B4;C3-C4))
	double_t chorda = 0;
	mLine* dl = new mLine(start,end);
	chorda = dl->getLength();

	angle = 2.0 * asin(chorda/(radious*2.0));//TODOH angle +180
}