//---------------------------------------------------------------------------------------
/*!
    \file abstractresource.h
    \brief 
*/
//---------------------------------------------------------------------------------------

// Include Header File
#include "abstractresource.h"

// Include Qt Files
#include <QBitArray>
#include <QDate>
#include <QDateTime>
#include <QLine>
#include <QLineF>
#include <QLocale>
#include <QPoint>
#include <QPointF>
#include <QRect>
#include <QRectF>
#include <QRegExp>
#include <QSize>
#include <QSizeF>
#include <QStringList>
#include <QTime>
#include <QUrl>

//---------------------------------------------------------------------------------------
using namespace Toolkit::Resource;

//---------------------------------------------------------------------------------------
/*!
    \brief Null value variant.

    It is used in AbstractResource::toVariant() to return a reference to a null variant.
*/
const QVariant AbstractResource::NULL_VALUE;

//---------------------------------------------------------------------------------------
/*!
    \brief Constructs a resource with a given key.

    \param key The key to assign to the resource. The key is optional.
*/
AbstractResource::AbstractResource( const QString& key ) :
    m_Key( key )
{
};

/*!
    \brief Copy constructor.

    Normal implementation.
*/
AbstractResource::AbstractResource( const AbstractResource& other ) :
    m_Key( other.m_Key )
{
};

/*!
    \brief Destructor.
*/
AbstractResource::~AbstractResource() {
};

/*!
    \brief Returns the key of this resource.
*/
const QString& AbstractResource::getKey() const {
    return m_Key;
};

/*!
    \brief Assigns a new key to this resource.

    \param key The key to assign.
*/
void AbstractResource::setKey( const QString& newKey ) {
    m_Key = newKey;
};

/*!
    \brief Returns the value of this resource as a QBitArray.

    \copydetails AbstractResource::doToBitArray()
*/
QBitArray AbstractResource::toBitArray() const {
    return doToBitArray();
};

/*!
    \brief Returns the value of this resource as a bool.

    \copydetails AbstractResource::doToBool()
*/
bool AbstractResource::toBool() const {
    return doToBool();
};

/*!
    \brief Returns the value of this resource as a QByteArray.

    \copydetails AbstractResource::doToByteArray()
*/
QByteArray AbstractResource::toByteArray() const {
    return doToByteArray();
};

/*!
    \brief

    \copydetails AbstractResource::doToChar()
*/
QChar AbstractResource::toChar() const {
    return doToChar();
};

/*!
    \brief

    \copydetails AbstractResource::doToDate()
*/
QDate AbstractResource::toDate() const {
    return doToDate();
};

/*!
    \brief

    \copydetails AbstractResource::doToDateTime()
*/
QDateTime AbstractResource::toDateTime() const {
    return doToDateTime();
};

/*!
    \brief

    \copydetails AbstractResource::doToDouble()
*/
double AbstractResource::toDouble( bool* ok ) const {
    return doToDouble( ok );
};

/*!
    \brief

    \copydetails AbstractResource::doToHash()
*/
QHash<QString, QVariant> AbstractResource::toHash() const {
    return doToHash();
};

/*!
    \brief

    \copydetails AbstractResource::doToInt()
*/
int AbstractResource::toInt( bool* ok ) const {
    return doToInt( ok );
};

/*!
    \brief

    \copydetails AbstractResource::doToLine()
*/
QLine AbstractResource::toLine() const {
    return doToLine();
};

/*!
    \brief

    \copydetails AbstractResource::doToLineF()
*/
QLineF AbstractResource::toLineF() const {
    return doToLineF();
};

/*!
    \brief

    \copydetails AbstractResource::doToList()
*/
QList<QVariant> AbstractResource::toList() const {
    return doToList();
};

/*!
    \brief

    \copydetails AbstractResource::doToLocale()
*/
QLocale AbstractResource::toLocale() const {
    return doToLocale();
};

/*!
    \brief

    \copydetails AbstractResource::doToLongLong()
*/
qlonglong AbstractResource::toLongLong( bool* ok ) const {
    return doToLongLong( ok );
};

/*!
    \brief

    \copydetails AbstractResource::doToMap()
*/
QMap<QString, QVariant> AbstractResource::toMap() const {
    return doToMap();
};

/*!
    \brief

    \copydetails AbstractResource::doToPoint()
*/
QPoint AbstractResource::toPoint() const {
    return doToPoint();
};

/*!
    \brief

    \copydetails AbstractResource::doToPointF()
*/
QPointF AbstractResource::toPointF() const {
    return doToPointF();
};

/*!
    \brief

    \copydetails AbstractResource::doToRect()
*/
QRect AbstractResource::toRect() const {
    return doToRect();
};

/*!
    \brief

    \copydetails AbstractResource::doToRectF()
*/
QRectF AbstractResource::toRectF() const {
    return doToRectF();
};

/*!
    \brief

    \copydetails AbstractResource::doToRegExp()
*/
QRegExp AbstractResource::toRegExp() const {
    return doToRegExp();
};

/*!
    \brief

    \copydetails AbstractResource::doToSize()
*/
QSize AbstractResource::toSize() const {
    return doToSize();
};

/*!
    \brief

    \copydetails AbstractResource::doToSizeF()
*/
QSizeF AbstractResource::toSizeF() const {
    return doToSizeF();
};

/*!
    \brief

    \copydetails AbstractResource::doToString()
*/
QString AbstractResource::toString() const {
    return doToString();
};

/*!
    \brief

    \copydetails AbstractResource::doToStringList()
*/
QStringList AbstractResource::toStringList() const {
    return doToStringList();
};

/*!
    \brief

    \copydetails AbstractResource::doToTime()
*/
QTime AbstractResource::toTime() const {
    return doToTime();
};

/*!
    \brief

    \copydetails AbstractResource::doToUInt()
*/
uint AbstractResource::toUInt( bool* ok ) const {
    return doToUInt( ok );
};

/*!
    \brief

    \copydetails AbstractResource::doToULongLong()
*/
qulonglong AbstractResource::toULongLong( bool* ok ) const {
    return doToULongLong( ok );
};

/*!
    \brief

    \copydetails AbstractResource::doToUrl()
*/
QUrl AbstractResource::toUrl() const {
    return doToUrl();
};

/*!
    \brief

    \copydetails AbstractResource::doToVariant()
*/
const QVariant& AbstractResource::toVariant() const {
    return doToVariant();
};

/*!
    \brief Assignment operator.

    \param other The resource to assign.

    \returns
        This instance.
*/
AbstractResource& AbstractResource::operator=( const AbstractResource& other ) {
    m_Key = other.m_Key;
    
    return *this;
};

/*!
    \brief Returns the value of this resource as a QBitArray.

    Returns an empty QBitArray if this resource can not be converted to a QBitArray.

    \sa
        <a href="/local-doc/qt-head/html/qvariant.html#toBitArray">QVariant::toBitArray()</a>
*/
QBitArray AbstractResource::doToBitArray() const {
    return toVariant().toBitArray();
};

/*!
    \brief Returns the value of this resource as a bool.

    Returns \e false if this resource can not be converted to a bool.

    \sa
        <a href="/local-doc/qt-head/html/qvariant.html#toBool">QVariant::toBool()</a>
*/
bool AbstractResource::doToBool() const {
    return toVariant().toBool();
};

/*!
    \brief Returns the value of this resource as a QByteArray.

    Returns an empty QByteArray if this resource can not be converted to a QByteArray.

    \sa
        <a href="/local-doc/qt-head/html/qvariant.html#toByteArray">QVariant::toByteArray()</a>
*/
QByteArray AbstractResource::doToByteArray() const {
    return toVariant().toByteArray();
};

QChar AbstractResource::doToChar() const {
    return toVariant().toChar();
};

QDate AbstractResource::doToDate() const {
    return toVariant().toDate();
};

QDateTime AbstractResource::doToDateTime() const {
    return toVariant().toDateTime();
};

double AbstractResource::doToDouble( bool* ok ) const {
    return toVariant().toDouble( ok );
};

QHash<QString, QVariant> AbstractResource::doToHash() const {
    return toVariant().toHash();
};

int AbstractResource::doToInt( bool* ok ) const {
    return toVariant().toInt( ok );
};

QLine AbstractResource::doToLine() const {
    return toVariant().toLine();
};

QLineF AbstractResource::doToLineF() const {
    return toVariant().toLineF();
};

QList<QVariant> AbstractResource::doToList() const {
    return toVariant().toList();
};

QLocale AbstractResource::doToLocale() const {
    return toVariant().toLocale();
};

qlonglong AbstractResource::doToLongLong( bool* ok ) const {
    return toVariant().toLongLong( ok );
};

QMap<QString, QVariant> AbstractResource::doToMap() const {
    return toVariant().toMap();
};

QPoint AbstractResource::doToPoint() const {
    return toVariant().toPoint();
};

QPointF AbstractResource::doToPointF() const {
    return toVariant().toPointF();
};

QRect AbstractResource::doToRect() const {
    return toVariant().toRect();
};

QRectF AbstractResource::doToRectF() const {
    return toVariant().toRectF();
};

QRegExp AbstractResource::doToRegExp() const {
    return toVariant().toRegExp();
};

QSize AbstractResource::doToSize() const {
    return toVariant().toSize();
};

QSizeF AbstractResource::doToSizeF() const {
    return toVariant().toSizeF();
};

QString AbstractResource::doToString() const {
    return toVariant().toString();
};

QStringList AbstractResource::doToStringList() const {
    return toVariant().toStringList();
};

QTime AbstractResource::doToTime() const {
    return toVariant().toTime();
};

uint AbstractResource::doToUInt( bool* ok ) const {
    return toVariant().toUInt( ok );
};

qulonglong AbstractResource::doToULongLong( bool* ok ) const {
    return toVariant().toULongLong( ok );
};

QUrl AbstractResource::doToUrl() const {
    return toVariant().toUrl();
};

const QVariant& AbstractResource::doToVariant() const {
    return NULL_VALUE;
};

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
