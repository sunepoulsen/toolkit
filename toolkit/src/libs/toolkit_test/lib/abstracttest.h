//-------------------------------------------------------------------------
/*!
    \file abstracttest.h
    \brief
*/

//-------------------------------------------------------------------------
#ifndef __TOOLKIT_TEST_ABSTRACTTEST_H__
#define __TOOLKIT_TEST_ABSTRACTTEST_H__

// Include Toolkit Test Files
#include "defines.h"

// Include QT Files
#include <QObject>
#include <QSharedPointer>

//-------------------------------------------------------------
namespace Toolkit {
    
    namespace Test {
	//-------------------------------------------------------------------------
	/*!
            \ingroup grp_Test
            \brief
	*/
	class TOOLKIT_TEST_API AbstractTest : public QObject {
            Q_OBJECT

	public:
            static const QRegExp TESTNAME_METHOD_PATTERN;

	public:
            //!\name Constructors & Destructor
            //@{
            AbstractTest();
            AbstractTest( const QString& id );
            AbstractTest( const AbstractTest& other );
            virtual ~AbstractTest();
            //@}
            
            //!\name Properties
            //@{
            virtual QString getId() const;
            virtual void setId( const QString& newId );
            //@}

            //!\name Tests
            //@{
            int countTests() const;
            //@}
            
            //!\name Register
            //@{
            QStringList registerTestCallers() const;
            //@}

            //!\name Operators
            //@{
            AbstractTest& operator=( const AbstractTest& other );
            //@}

	private:
            //!\name Tests
            //@{
            virtual int doCountTests() const;
            //@}
            
            //!\name Register
            //@{
            virtual QStringList doRegisterTestCallers() const;
            //@}


	private:
            QString m_Id;
	};

	//-------------------------------------------------------------------------
	/*!
		\brief
	*/
	class TOOLKIT_TEST_API FindTestById {
	public:
            //!\name Constructors & Destructor
            //@{
            FindTestById( const QString& id );
            virtual ~FindTestById();
            //@}

            //!\name Operators
            //@{
            bool operator()( const QSharedPointer<AbstractTest>& test ) const;
            bool operator()( const AbstractTest* test ) const;
            bool operator()( const AbstractTest& test ) const;
            //@}

	private:
            QString m_Id;
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
