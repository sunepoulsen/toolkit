//-------------------------------------------------------------------------------------------------
/*!
    \file genericmodel.h
    \brief
*/

//-------------------------------------------------------------------------------------------------
#ifndef __TOOLKIT_CORE_GENERICMODEL_H__
#define __TOOLKIT_CORE_GENERICMODEL_H__

// Include Toolkit Core Files
#include "defines.h"
#include "modelcolumns.h"
#include "modelitem.h"

// Include Qt Files
#include <QAbstractItemModel>

// Include STD Files
#include <vector>

//-------------------------------------------------------------------------------------------------
namespace Toolkit {

    namespace Core {
        //---------------------------------------------------------------------------------------------
        /*!
            \brief
            \ingroup grp_Models
        */
        class TOOLKIT_CORE_API GenericModel : public QAbstractItemModel {
        public:
            //!\name Constructors & Destructor
            //@{
            GenericModel( QObject* parent = NULL, ModelItem* root = NULL );
            virtual ~GenericModel();
            //@}

            //!\name Properties
            //@{
            const ModelItem* getRoot() const;
            ModelItem* getRoot();
            void setRoot( ModelItem* newModelItem );
            const ModelColumnContainer& getColumns() const;
            ModelColumnContainer& getColumns();
            void setColumns( const ModelColumnContainer& newColumns );
            //@}

            //!\name Qt Model
            //@{
            virtual int rowCount( const QModelIndex& parent = QModelIndex() ) const;
            virtual int columnCount( const QModelIndex& parent = QModelIndex() ) const;
            virtual QModelIndex index( int row, int column, const QModelIndex & parent = QModelIndex() ) const;
            virtual QModelIndex parent( const QModelIndex& index ) const;
            virtual bool canFetchMore( const QModelIndex& parent ) const;
            virtual void fetchMore( const QModelIndex& parent );
            virtual bool hasChildren( const QModelIndex& parent = QModelIndex() ) const;
            virtual Qt::ItemFlags flags( const QModelIndex& index ) const;
            virtual QVariant data( const QModelIndex& index, int role = Qt::DisplayRole ) const;
            virtual bool setData( const QModelIndex& index, const QVariant& value, int role = Qt::EditRole );
            virtual QVariant headerData( int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const;
            virtual void sort( int column, Qt::SortOrder order = Qt::AscendingOrder );
            //@}

        private:
            ModelColumnContainer::const_iterator findColumn( const QModelIndex& index ) const;
            ModelItem::const_iterator findItem( const ModelItem* modelItem, const QModelIndex& index ) const;
            ModelItem::iterator findItem( ModelItem* modelItem, const QModelIndex& index );

        private:
            ModelItem* m_Root;
            ModelColumnContainer m_Columns;

        private:
            Q_DISABLE_COPY( GenericModel )
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
