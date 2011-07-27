//---------------------------------------------------------------------------------------
/*!
    \file packagefactory.h
    \brief
*/

//---------------------------------------------------------------------------------------
#ifndef __TOOLKIT_SCRIPT_PACKAGEFACTORY_H__
#define __TOOLKIT_SCRIPT_PACKAGEFACTORY_H__

// Include Toolkit Script Files
#include "defines.h"

// Include Toolkit Script Files
#include "abstractpackage.h"

// Include Qt Files
#include <QObject>
#include <QScriptable>

//---------------------------------------------------------------------------------------
namespace Toolkit {

    namespace Script {
        //---------------------------------------------------------------------------------------
        /*!
            \ingroup grp_Script
            \brief Factory class to produce a package to the script engine module system.
        */
        class TOOLKIT_SCRIPT_API PackageFactory {
        public:
            //!\name Constants
            //@{
            static const QString NAMESPACE;
            static const QString QCHAR_CLASS_NAME;
            static const QString STRING_CLASS_NAME;
            //@}

            //!\name Factory functions
            //@{
            static AbstractPackage::Pointer newPackage( const QString& ns = NAMESPACE );
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
