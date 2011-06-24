//----------------------------------------------------------------------------------------------
/*!
    \file profiler.cpp
    \brief
*/

//----------------------------------------------------------------------------------------------

// Include Header File
#include "profiler.h"

//----------------------------------------------------------------------------------------------
using namespace Toolkit::Core;

//----------------------------------------------------------------------------------------------
Profiler::Profiler( size_type reserveSize ) :
    m_Elaps(),
    m_Timer()
{
    if( reserveSize > 0 ) {
        m_Elaps.reserve( reserveSize );
    }
}

Profiler::Profiler( const Profiler& other ) :
    m_Elaps( other.m_Elaps ),
    m_Timer( other.m_Timer )
{
}

Profiler::~Profiler() {
}

void Profiler::start() {
    m_Timer.restart();
}

void Profiler::stop() {
    m_Elaps.push_back( m_Timer.elapsed() );
}

int Profiler::min() const {
    if( m_Elaps.empty() ) {
        return 0;
    };

    int result = *m_Elaps.begin();
    for( const_iterator it = m_Elaps.begin() + 1; it != m_Elaps.end(); ++it ) {
        if( *it < result ) {
            result = *it;
        }
    }

    return result;
}

int Profiler::max() const {
    if( m_Elaps.empty() ) {
        return 0;
    };

    int result = *m_Elaps.begin();
    for( const_iterator it = m_Elaps.begin() + 1; it != m_Elaps.end(); ++it ) {
        if( *it > result ) {
            result = *it;
        }
    }

    return result;
}

int Profiler::sum() const {
    int result = 0;
    for( const_iterator it = m_Elaps.begin(); it != m_Elaps.end(); ++it ) {
        result += *it;
    }

    return result;
}

int Profiler::count() const {
    return m_Elaps.size();
}

double Profiler::avg() const {
    return (double)sum() / (double)count();
}

Profiler& Profiler::operator=( const Profiler& other ) {
    m_Elaps = other.m_Elaps;
    m_Timer = other.m_Timer;

    return *this;
}

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=8 fdm=marker
 * vim<600: sw=4 ts=8
 */
