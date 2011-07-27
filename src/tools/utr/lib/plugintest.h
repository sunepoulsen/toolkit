//-------------------------------------------------------------------------------------------------------
/*!
    \file plugintest.h
    \brief
*/

//-------------------------------------------------------------------------------------------------------
#ifndef __TOOLKIT_TEST_UTR_PLUGINTEST_H__
#define __TOOLKIT_TEST_UTR_PLUGINTEST_H__

// Include Toolkit Utr Files
#include "abstractpluginitem.h"

// Include Toolkit Test Files
#include <toolkit/test/abstracttest.h>
#include <toolkit/test/testsuite.h>

//-------------------------------------------------------------------------------------------------------
/*!
    \ingroup grp_TestExecutor
    \brief
*/
class PluginTest : public AbstractPluginItem {
public:
    //\!name Constructors & Destructor
    //@{
    PluginTest( AbstractPluginItem* parent = NULL, Toolkit::Test::TestSuite::value_type test = Toolkit::Test::TestSuite::value_type() );
    virtual ~PluginTest();
    //@}

    //!\name Properties
    //@{
    Toolkit::Test::TestSuite::value_type getTest();
    const Toolkit::Test::TestSuite::value_type getTest() const;
    void setTest( Toolkit::Test::TestSuite::value_type newTest );
    //@}

protected:
    //!\name Model interface
    //@{
    virtual QVariant doModelData( Toolkit::Core::ModelColumnContainer::const_iterator colIt, int role = Qt::DisplayRole ) const;
    //@}

private:
    void setupTest();

private:
    Toolkit::Test::TestSuite::value_type m_Test;
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
