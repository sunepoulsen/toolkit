//---------------------------------------------------------------------------------------
/*!
    \file abstractoperation.h
    \brief 
*/

//---------------------------------------------------------------------------------------
#ifndef __TOOLKIT_SQL_ABSTRACTOPERATION_H__
#define __TOOLKIT_SQL_ABSTRACTOPERATION_H__

// Include Toolkit Sql Files
#include "defines.h"

// Include Qt Files
#include <QObject>
#include <QSharedPointer>
#include <QSqlDatabase>

//---------------------------------------------------------------------------------------
namespace Toolkit {
       
    namespace Sql {
        //---------------------------------------------------------------------------------------
        /*!
            \ingroup grp_Sql
            \brief Implements an abstract interface for a database operation.

            \par Responsability

            Responsability...

            \par Memory Management

            Memory Management...
        */
        class TOOLKIT_SQL_API AbstractOperation : public QObject {
            Q_OBJECT

        public:
            /*!
                \brief Typedef of a shared AbstractOperation pointer.
            */
            typedef QSharedPointer<AbstractOperation> Ptr;

        signals:
            //!\name States
            //@{
            /*!
                \brief Emited when this operation is started.

                \param owner A pointer to this instance.
            */
            void started( AbstractOperation* owner );

            /*!
                \brief Emited when the state of this operation is changed.

                \e progressTotal and \e progressValue is used in a GUI to show the user
                how complete this operation is.

                \param owner         A pointer to this instance.
                \param progressTotal The total amount of progress.
                \param progressValue The current value of the progress.

                \note
                    The total progress is included in the signal, because of the total amount may
                    change doing the operation.
            */
            void change( AbstractOperation* owner, int progressTotal, int progressValue );

            /*!
                \brief Emited when this operation is done.

                \param owner A pointer to this instance.
            */
            void finished( AbstractOperation* owner );
            //@}

            //!\name Operations
            //@{
            /*!
                \brief Emited when this operation needs to create an extra operation to be executed.

                The new operation should be appended to the container of database operations.

                \param owner A shared pointer to the new operation.
            */
            void createOperation( const Ptr& owner );
            //@}

        public:
            //!\name Constructors & Destructor
            //@{
            AbstractOperation();
            virtual ~AbstractOperation();
            //@}

            //!\name Properties
            //@{
            const QString& getName() const;
            void setName( const QString& newName );
            const QString& getDescription() const;
            void setDescription( const QString& newDescription );
            const QSqlDatabase& getDatabase() const;
            void setDatabase( const QSqlDatabase& newDatabase );
            //@}

        private:
            //!\name Properties
            //@{
            /*!
                \brief The name of this operation.

                It is intended to be used in model/views.
            */
            QString m_Name;

            /*!
                \brief Description of what the operation does.
            */
            QString m_Description;

            /*!
                \brief The database connection to operation on.
            */
            QSqlDatabase m_Database;
            //@}

        private:
            Q_DISABLE_COPY( AbstractOperation )
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
