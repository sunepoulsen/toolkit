//---------------------------------------------------------------------------------------
/*!
    \file filepackage.cpp
    \brief
*/

//---------------------------------------------------------------------------------------

// Include Header File
#include "filepackage.h"

//---------------------------------------------------------------------------------------
using namespace Toolkit::Script;

//---------------------------------------------------------------------------------------
const QString FilePackage::DEFAULT_FILE_PATTERN( "*.js" );

//---------------------------------------------------------------------------------------
FilePackage::FilePackage( const QUrl& url, const QString& ns ) :
    AbstractPackage(),
    m_NameSpace( ns ),
    m_FilePattern( DEFAULT_FILE_PATTERN ),
    m_Urls()
{
    push_back( url );
};

FilePackage::FilePackage( const FilePackage& other ) :
    AbstractPackage( other ),
    m_NameSpace( other.m_NameSpace ),
    m_FilePattern( other.m_FilePattern ),
    m_Urls( other.m_Urls )
{
};

FilePackage::~FilePackage() {
};

const QString& FilePackage::getNameSpace() const {
    return m_NameSpace;
};

void FilePackage::setNameSpace( const QString& newNameSpace ) {
    m_NameSpace = newNameSpace;
};

const QString& FilePackage::getFilePattern() const {
    return m_FilePattern;
};

void FilePackage::setFilePattern( const QString& newFilePattern ) {
    m_FilePattern = newFilePattern;
};

FilePackage::iterator FilePackage::begin() {
    return m_Urls.begin();
};

FilePackage::const_iterator FilePackage::begin() const {
    return m_Urls.begin();
};

FilePackage::iterator FilePackage::end() {
    return m_Urls.end();
};

FilePackage::const_iterator FilePackage::end() const {
    return m_Urls.end();
};

void FilePackage::clear() {
    m_Urls.clear();
};

bool FilePackage::empty() const {
    return m_Urls.empty();
};

void FilePackage::push_back( const value_type& v ) {
    m_Urls.push_back( v );
};

FilePackage::size_type FilePackage::size() const {
    return m_Urls.size();
};

FilePackage& FilePackage::operator=( const FilePackage& other ) {
    m_NameSpace = other.m_NameSpace;
    m_FilePattern = other.m_FilePattern;
    m_Urls = other.m_Urls;

    return *this;
};

bool FilePackage::doCheckPackage( const QUrl& ) const {
    return false;
};

AbstractPackage::url_container FilePackage::doExtractPackageNames( const QUrl& ) const {
    return AbstractPackage::url_container();
};

void FilePackage::doLoadPackage( const QUrl&, QScriptContext*, Environment* ) const {
};

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
