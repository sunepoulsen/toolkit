//-----------------------------------------------------------------------------
/*!
    \file datamodel.h
    \brief
*/

//-----------------------------------------------------------------------------
#ifndef __TOOLKIT_CORE_DATAMODEL_H__
#define __TOOLKIT_CORE_DATAMODEL_H__

// Include Toolkit Files
#include "defines.h"
#include "modelcolumns.h"

// Include Qt Files
#include <QAbstractTableModel>

//-----------------------------------------------------------------------------
namespace Toolkit {

    namespace Core {
        //---------------------------------------------------------------------
        /*!
            \brief
        */
        class TOOLKIT_CORE_API DataModel : public QAbstractTableModel {
            Q_OBJECT

        public:
            //!\name Constructors & Destructor
            //@{
            DataModel( QObject* parent = NULL );
            DataModel( const DataModel* other, QObject* parent = NULL );
            virtual ~DataModel();
            //@}

            //!\name Properties
            //@{
            const ModelColumnContainer& getColumns() const;
            ModelColumnContainer& getColumns();
            void setColumns( const ModelColumnContainer& newColumns );
            //@}

        private:
            ModelColumnContainer m_Columns;

        private:
            Q_DISABLE_COPY( DataModel )
        };

    }

}

#endif

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
