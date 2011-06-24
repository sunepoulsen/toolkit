//----------------------------------------------------------------------------------------------
/*!
    \file profiler.h
    \brief
*/

//----------------------------------------------------------------------------------------------
#ifndef __TOOLKIT_CORE_PROFILER_H__
#define __TOOLKIT_CORE_PROFILER_H__

// Include Toolkit Core Files
#include "defines.h"

// Include Qt Files
#include <QTime>
#include <QVector>

//-------------------------------------------------------------------------------------------------
namespace Toolkit {

    namespace Core {
        //---------------------------------------------------------------------------------------------
        /*!
            \brief
            \ingroup grp_Core
        */
        class Profiler {
        public:
            typedef QVector<int> container_type;
            typedef container_type::iterator iterator;
            typedef container_type::const_iterator const_iterator;
            typedef container_type::size_type size_type;

        public:
            //!\name Constructors & Destructor
            //@{
            Profiler( size_type reserveSize = 0 );
            Profiler( const Profiler& other );
            virtual ~Profiler();
            //@}

            //!\name Timers
            //@{
            void start();
            void stop();
            //@}

            //!\name Statistics
            //@{
            int min() const;
            int max() const;
            int sum() const;
            int count() const;
            double avg() const;
            //@}

            //!\name Operators
            //@{
            Profiler& operator=( const Profiler& other );
            //@}

        private:
            container_type m_Elaps;
            QTime m_Timer;
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
