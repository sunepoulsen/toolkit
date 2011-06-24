//-------------------------------------------------------------------------------------------------------
/*!
    \file plugintestfuncitem.h
    \brief
*/

//-------------------------------------------------------------------------------------------------------
#ifndef __TOOLKIT_TEST_UTR_PLUGINTESTFUNCITEM_H__
#define __TOOLKIT_TEST_UTR_PLUGINTESTFUNCITEM_H__

// Include UTR Files
#include "abstractpluginitem.h"

// Include Toolkit Test Files
#include <toolkit/test/testcase.h>

//-------------------------------------------------------------------------------------------------------
/*!
    \ingroup grp_TestExecutor
    \brief    
*/
class PluginTestFuncItem : public AbstractPluginItem {
public:
	//!\name Constructors & Destructor
	//@{
	PluginTestFuncItem( Toolkit::Test::TestCasePtr testCase, const QString& funcName );
	virtual ~PluginTestFuncItem();
	//@}

	//!\name Properties
	//@{
    Toolkit::Test::TestCasePtr testCase() const;
	const QString& getFuncName() const;
	void setFuncName( const QString& newFuncName );
	//@}

protected:
	//!\name Model interface
	//@{
	virtual QVariant doModelData( Toolkit::Core::ModelColumnContainer::const_iterator colIt, int role = Qt::DisplayRole ) const;
	//@}

private:
	//!\name Properties
	//@{
    Toolkit::Test::TestCasePtr m_TestCase;
	QString m_FuncName;
	//@}

private:
    Q_DISABLE_COPY( PluginTestFuncItem );
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
