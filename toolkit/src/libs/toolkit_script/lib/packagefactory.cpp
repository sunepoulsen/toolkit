//---------------------------------------------------------------------------------------
/*!
    \file packagefactory.h
    \brief
*/

//---------------------------------------------------------------------------------------

// Include Header File
#include "packagefactory.h"

// Include Toolkit Script Files
#include "corepackage.h"
#include "registrationclass.h"
#include "jsqchar.h"
#include "jsstring.h"

//---------------------------------------------------------------------------------------
using namespace Toolkit::Script;

//---------------------------------------------------------------------------------------
const QString PackageFactory::NAMESPACE( "Toolkit.Core" );
const QString PackageFactory::QCHAR_CLASS_NAME( "QChar" );
const QString PackageFactory::STRING_CLASS_NAME( "String" );

//---------------------------------------------------------------------------------------
AbstractPackage::Pointer PackageFactory::newPackage( const QString& ns ) {
    CorePackage* package = new CorePackage( ns );

    //---------------------------------------------------------------------------------------
    //                     Register QChar class
    //---------------------------------------------------------------------------------------

    RegistrationClass* qcharClass = RegistrationClass::newClass<JSQChar>( QCHAR_CLASS_NAME );

    // Register QChar::Category properties
    qcharClass->getStaticProperties().insert( std::make_pair( "Mark_NonSpacing",          QChar::Mark_NonSpacing ) );
    qcharClass->getStaticProperties().insert( std::make_pair( "Mark_SpacingCombining",    QChar::Mark_SpacingCombining ) );
    qcharClass->getStaticProperties().insert( std::make_pair( "Mark_Enclosing",           QChar::Mark_Enclosing ) );
    qcharClass->getStaticProperties().insert( std::make_pair( "Number_DecimalDigit",      QChar::Number_DecimalDigit ) );
    qcharClass->getStaticProperties().insert( std::make_pair( "Number_Letter",            QChar::Number_Letter ) );
    qcharClass->getStaticProperties().insert( std::make_pair( "Number_Other",             QChar::Number_Other ) );
    qcharClass->getStaticProperties().insert( std::make_pair( "Separator_Space",          QChar::Separator_Space ) );
    qcharClass->getStaticProperties().insert( std::make_pair( "Separator_Line",           QChar::Separator_Line ) );
    qcharClass->getStaticProperties().insert( std::make_pair( "Separator_Paragraph",      QChar::Separator_Paragraph ) );
    qcharClass->getStaticProperties().insert( std::make_pair( "Other_Control",            QChar::Other_Control ) );
    qcharClass->getStaticProperties().insert( std::make_pair( "Other_Format",             QChar::Other_Format ) );
    qcharClass->getStaticProperties().insert( std::make_pair( "Other_Surrogate",          QChar::Other_Surrogate ) );
    qcharClass->getStaticProperties().insert( std::make_pair( "Other_PrivateUse",         QChar::Other_PrivateUse ) );
    qcharClass->getStaticProperties().insert( std::make_pair( "Other_NotAssigned",        QChar::Other_NotAssigned ) );
    qcharClass->getStaticProperties().insert( std::make_pair( "Letter_Uppercase",         QChar::Letter_Uppercase ) );
    qcharClass->getStaticProperties().insert( std::make_pair( "Letter_Lowercase",         QChar::Letter_Lowercase ) );
    qcharClass->getStaticProperties().insert( std::make_pair( "Letter_Titlecase",         QChar::Letter_Titlecase ) );
    qcharClass->getStaticProperties().insert( std::make_pair( "Letter_Modifier",          QChar::Letter_Modifier ) );
    qcharClass->getStaticProperties().insert( std::make_pair( "Letter_Other",             QChar::Letter_Other ) );
    qcharClass->getStaticProperties().insert( std::make_pair( "Punctuation_Connector",    QChar::Punctuation_Connector ) );
    qcharClass->getStaticProperties().insert( std::make_pair( "Punctuation_Dash",         QChar::Punctuation_Dash ) );
    qcharClass->getStaticProperties().insert( std::make_pair( "Punctuation_Open",         QChar::Punctuation_Open ) );
    qcharClass->getStaticProperties().insert( std::make_pair( "Punctuation_Close",        QChar::Punctuation_Close ) );
    qcharClass->getStaticProperties().insert( std::make_pair( "Punctuation_InitialQuote", QChar::Punctuation_InitialQuote ) );
    qcharClass->getStaticProperties().insert( std::make_pair( "Punctuation_FinalQuote",   QChar::Punctuation_FinalQuote ) );
    qcharClass->getStaticProperties().insert( std::make_pair( "Punctuation_Other",        QChar::Punctuation_Other ) );
    qcharClass->getStaticProperties().insert( std::make_pair( "Symbol_Math",              QChar::Symbol_Math ) );
    qcharClass->getStaticProperties().insert( std::make_pair( "Symbol_Currency",          QChar::Symbol_Currency ) );
    qcharClass->getStaticProperties().insert( std::make_pair( "Symbol_Modifier",          QChar::Symbol_Modifier ) );
    qcharClass->getStaticProperties().insert( std::make_pair( "Symbol_Other",             QChar::Symbol_Other ) );
    qcharClass->getStaticProperties().insert( std::make_pair( "NoCategory",               QChar::NoCategory ) );
    package->push_back( AbstractRegistrationObject::Pointer( qcharClass ) );

    //---------------------------------------------------------------------------------------
    //                     Register QChar class
    //---------------------------------------------------------------------------------------

    RegistrationClass* stringClass = new RegistrationClass( STRING_CLASS_NAME );

    // Static functions
    stringClass->getStaticFunctions().push_back( RegistrationFunction( "format", JSString::format ) );

    // Prototype functions
    stringClass->getDynamicFunctions().push_back( RegistrationFunction( "toInt", JSString::toInt ) );

    package->push_back( AbstractRegistrationObject::Pointer( stringClass ) );


    return AbstractPackage::Pointer( package );
}


/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
