//-------------------------------------------------------------------------
/*!
    \file packageinterface.h
    \brief
*/

//-------------------------------------------------------------------------
#ifndef __TOOLKIT_TEST_PACKAGEINTERFACE_H__
#define __TOOLKIT_TEST_PACKAGEINTERFACE_H__

// Include Toolkit Script Files
#include "defines.h"
#include "packagehandler.h"

// Include QT Files
#include <QSharedPointer>
#include <QtPlugin>

//---------------------------------------------------------------------------------------
namespace Toolkit {

    namespace Script {
        //-------------------------------------------------------------------------
        /*!
            \ingroup grp_Script
            \brief
        */
        class TOOLKIT_SCRIPT_API PackageInterface {
        public:
            //!\name Types
            //@{
            typedef QSharedPointer<PackageInterface> Pointer;
            //@}

        public:
            //!\name Constructors & Destructor
            //@{
            virtual ~PackageInterface();
            //@}

            //!\name Plugin Interface
            //@{
            virtual QString pluginName() const = 0;
            virtual QString pluginDescription() const = 0;
            virtual QString pluginVersion() const = 0;
            //@}

            //!\name Test Registration
            //@{
            virtual PackageHandler::container_type registerPackages() const = 0;
            //@}
        };
    };
};

Q_DECLARE_INTERFACE( Toolkit::Script::PackageInterface, "com.stp.Toolkit_Script.PackageInterface/1.0" )

#endif

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
