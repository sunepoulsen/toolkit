//---------------------------------------------------------------------------------------
/*!
    \file abstractresource.h
    \brief 
*/

//---------------------------------------------------------------------------------------
#ifndef __TOOLKIT_RESOURCE_ABSTRACTRESOURCE_H__
#define __TOOLKIT_RESOURCE_ABSTRACTRESOURCE_H__

// Include Toolkit Resource Files
#include "defines.h"

// Include Qt Files
#include <QSharedPointer>
#include <QVariant>

// Include Toolkit Core Files
#include <toolkit/core/genericexception.h>

//---------------------------------------------------------------------------------------
namespace Toolkit {
       
    namespace Resource {
        //---------------------------------------------------------------------------------------
        typedef Toolkit::Core::GenericException ResourceException;

        //---------------------------------------------------------------------------------------
        /*!
            \ingroup grp_Resources
            \brief Abstract class that declares the interface of a resource.
        */
        class TOOLKIT_RESOURCE_API AbstractResource {
        public:
            typedef QSharedPointer<AbstractResource> Pointer;

        public:
            static const QVariant NULL_VALUE;

        public:
            //!\name Constructors & Destructor
            //@{
            AbstractResource( const QString& key = QString::null );
            AbstractResource( const AbstractResource& other );
            virtual ~AbstractResource();
            //@}
            
            //!\name Properties
            //@{
            const QString& getKey() const;
            void setKey( const QString& newKey );
            //@}
            
            //!\name Converters
            //@{
            QBitArray toBitArray() const;
            bool toBool() const;
            QByteArray toByteArray() const;
            QChar toChar() const;
            QDate toDate() const;
            QDateTime toDateTime() const;
            double toDouble( bool* ok = 0 ) const;
            QHash<QString, QVariant> toHash() const;
            int toInt( bool* ok = 0 ) const;
            QLine toLine() const;
            QLineF toLineF() const;
            QList<QVariant> toList() const;
            QLocale toLocale() const;
            qlonglong toLongLong( bool* ok = 0 ) const;
            QMap<QString, QVariant> toMap() const;
            QPoint toPoint() const;
            QPointF toPointF() const;
            QRect toRect() const;
            QRectF toRectF() const;
            QRegExp toRegExp() const;
            QSize toSize() const;
            QSizeF toSizeF() const;
            QString toString() const;
            QStringList toStringList() const;
            QTime toTime() const;
            uint toUInt( bool* ok = 0 ) const;
            qulonglong toULongLong( bool* ok = 0 ) const;
            QUrl toUrl() const;
            const QVariant& toVariant() const;
            //@}
            
            //!\name Operators
            //@{
            AbstractResource& operator=( const AbstractResource& other );
            //@}
        
        private:
            //!\name Converters
            //@{
            virtual QBitArray doToBitArray() const;
            virtual bool doToBool() const;
            virtual QByteArray doToByteArray() const;
            virtual QChar doToChar() const;
            virtual QDate doToDate() const;
            virtual QDateTime doToDateTime() const;
            virtual double doToDouble( bool* ok = 0 ) const;
            virtual QHash<QString, QVariant> doToHash() const;
            virtual int doToInt( bool* ok = 0 ) const;
            virtual QLine doToLine() const;
            virtual QLineF doToLineF() const;
            virtual QList<QVariant> doToList() const;
            virtual QLocale doToLocale() const;
            virtual qlonglong doToLongLong( bool* ok = 0 ) const;
            virtual QMap<QString, QVariant> doToMap() const;
            virtual QPoint doToPoint() const;
            virtual QPointF doToPointF() const;
            virtual QRect doToRect() const;
            virtual QRectF doToRectF() const;
            virtual QRegExp doToRegExp() const;
            virtual QSize doToSize() const;
            virtual QSizeF doToSizeF() const;
            virtual QString doToString() const;
            virtual QStringList doToStringList() const;
            virtual QTime doToTime() const;
            virtual uint doToUInt( bool* ok = 0 ) const;
            virtual qulonglong doToULongLong( bool* ok = 0 ) const;
            virtual QUrl doToUrl() const;
            virtual const QVariant& doToVariant() const;
            //@}
            
        private:
            //!\name Properties
            //@{
            QString m_Key;
            //@}
        };
    
    };
    
};

#endif

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
