//---------------------------------------------------------------------------------------
/*!
    \file filepackage.h
    \brief
*/

//---------------------------------------------------------------------------------------
#ifndef __TOOLKIT_SCRIPT_FILEPACKAGE_H__
#define __TOOLKIT_SCRIPT_FILEPACKAGE_H__

// Include Toolkit Script Files
#include "abstractpackage.h"

// Include Qt Files
#include <QUrl>

// Include STD Files
#include <vector>

//---------------------------------------------------------------------------------------
namespace Toolkit {

    namespace Script {
        //---------------------------------------------------------------------------------------
        /*!
            \ingroup grp_Script
            \brief
        */
        class TOOLKIT_SCRIPT_API FilePackage : public AbstractPackage {
        public:
            typedef std::vector<QUrl> container_type;
            typedef container_type::iterator iterator;
            typedef container_type::const_iterator const_iterator;
            typedef container_type::value_type value_type;
            typedef container_type::size_type size_type;

            static const QString DEFAULT_FILE_PATTERN;

        public:
            //!\name Constructors & Destructor
            //@{
            FilePackage( const QUrl& url, const QString& ns = QString() );
            FilePackage( const FilePackage& other );
            virtual ~FilePackage();
            //@}

            //!\name Properties
            //@{
            const QString& getNameSpace() const;
            void setNameSpace( const QString& newNameSpace );
            const QString& getFilePattern() const;
            void setFilePattern( const QString& newFilePattern );
            //@}

            //!\name Items
            //@{
            iterator begin();
            const_iterator begin() const;
            iterator end();
            const_iterator end() const;
            void clear();
            bool empty() const;
            void push_back( const value_type& v );
            size_type size() const;
            //@}

            //!\name Operators
            //@{
            FilePackage& operator=( const FilePackage& other );
            //@}

        private:
            //!\name Package interface
            //@{
            virtual bool doCheckPackage( const QUrl& packageName ) const;
            virtual url_container doExtractPackageNames( const QUrl& packageName ) const;
            virtual void doLoadPackage( const QUrl& packageName, QScriptContext* ctx, Environment* eng ) const;
            //@}

        private:
            //!\name Properties
            //@{
            QString m_NameSpace;
            QString m_FilePattern;
            container_type m_Urls;
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
