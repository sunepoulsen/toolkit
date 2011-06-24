//-------------------------------------------------------------------------
/*!
    \file testsuite.h
    \brief
*/

//-------------------------------------------------------------------------
#ifndef __TOOLKIT_TEST_TESTSUITE_H__
#define __TOOLKIT_TEST_TESTSUITE_H__

// Include Toolkit Test Files
#include "defines.h"
#include "abstracttest.h"

// Include QT Files
#include <QSharedPointer>
#include <QString>

// Include STD Files
#include <vector>

//-------------------------------------------------------------
namespace Toolkit {
    
    namespace Test {
        //-------------------------------------------------------------------------
        /*!
            \ingroup grp_Test
            \brief
        */
        class TOOLKIT_TEST_API TestSuite : public AbstractTest {
            Q_OBJECT
                
        public:
            typedef QSharedPointer<AbstractTest> item_type;
            typedef std::vector<item_type> container_type;
            typedef container_type::iterator iterator;
            typedef container_type::const_iterator const_iterator;
            typedef container_type::reference reference;
            typedef container_type::const_reference const_reference;
            typedef container_type::size_type size_type;
            typedef container_type::value_type value_type;
    
        public:
            //!\name Constructors & Destructor
            //@{
            TestSuite();
            TestSuite( const QString& id );
            TestSuite( const TestSuite& other );
            virtual ~TestSuite();
            //@}
    
            //!\name Tests
            //@{
            iterator begin();
            const_iterator begin() const;
            iterator end();
            const_iterator end() const;
            void addTest( const value_type& v );
            void clear();
            void erase( iterator pos );
            void erase( iterator __begin, iterator __end );
            iterator findTest( const QString& id );
            const_iterator findTest( const QString& id ) const;
            size_type size() const;
            //@}
    
            //!\name Operators
            //@{
            TestSuite& operator=( const TestSuite& other );
            reference operator[]( size_type n );
            const_reference operator[]( size_type n ) const;
            //@}
    
        private:
            //!\name Tests
            //@{
            virtual int doCountTests() const;
            //@}
    
        private:
            container_type m_Tests;
        };
        
        //-------------------------------------------------------------------------
        typedef QSharedPointer<TestSuite> TestSuitePtr;
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
