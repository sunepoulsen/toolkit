//-------------------------------------------------------------
/*!
  \file abstractformat_imp.h
  \brief 
*/

//-------------------------------------------------------------

#ifndef __TOOLKIT_CORE_ABSTRACTFORMAT_IMP_H__
#define __TOOLKIT_CORE_ABSTRACTFORMAT_IMP_H__

//-------------------------------------------------------------
//      Implementation of template functions.
//-------------------------------------------------------------

//-------------------------------------------------------------
template< typename formaterType >
AbstractFormat<formaterType>::AbstractFormat( const QLocale& locale, const formaterType& formater ) :
    m_Locale( locale ),
    m_Formater( formater )
{
};

template< typename formaterType >
AbstractFormat<formaterType>::AbstractFormat( const AbstractFormat& other ) :
    m_Locale( other.m_Locale ),
    m_Formater( other.m_Formater )
{
};

template< typename formaterType >
AbstractFormat<formaterType>::~AbstractFormat() {
};

template< typename formaterType >
void AbstractFormat<formaterType>::writeString( const QString& str ) {
    doWriteString( str );
};

template< typename formaterType >
void AbstractFormat<formaterType>::printf( const QString& str ) {
    writeString( str );
};

template< typename formaterType >
template< typename T1 >
void AbstractFormat<formaterType>::printf( const QString& format, T1 p1 ) {
    QRegExp rx( FormatParam::PARAM_PATTERN );
    int nextParam = 1;
    
    if( rx.indexIn( format ) == -1 ) {
        writeString( format );
        return;
    };
    
    int pos = 0;
    int rxPos;
    int curParam;
    while( (rxPos = rx.indexIn( format, pos )) > -1 ) {
        writeString( format.mid( pos, rxPos - pos ) );
        
        if( rx.cap() == FormatParam::PARAM_PREFIX_ESCAPE ) {
            writeString( FormatParam::PARAM_PREFIX_CHAR );
        }
        else {
            FormatParam param( rx );

            curParam = param.getArgIndex();
            if( curParam < 1 ) {
                curParam = nextParam;
            };

            if( curParam == 1 ) {
                writeString( m_Formater.format( m_Locale, param, p1 ) );
            }
            else {
                writeString( format.mid( rxPos, rx.matchedLength() ) );
            };
        };
            
        nextParam++;
        pos = rxPos + rx.matchedLength();
    };
    
    writeString( format.mid( pos ) );
};

template< typename formaterType >
template< typename T1, typename T2 >
void AbstractFormat<formaterType>::printf( const QString& format, T1 p1, T2 p2 ) {
    QRegExp rx( FormatParam::PARAM_PATTERN );
    int nextParam = 1;
    
    if( rx.indexIn( format ) == -1 ) {
        writeString( format );
        return;
    };
    
    int pos = 0;
    int rxPos;
    int curParam;
    while( (rxPos = rx.indexIn( format, pos )) > -1 ) {
        writeString( format.mid( pos, rxPos - pos ) );
        
        if( rx.cap() == FormatParam::PARAM_PREFIX_ESCAPE ) {
            writeString( FormatParam::PARAM_PREFIX_CHAR );
        }
        else {
            FormatParam param( rx );

            curParam = param.getArgIndex();
            if( curParam < 1 ) {
                curParam = nextParam;
            };

            if( curParam == 1 ) {
                writeString( m_Formater.format( m_Locale, param, p1 ) );
            }
            else if( curParam == 2 ) {
                writeString( m_Formater.format( m_Locale, param, p2 ) );
            }
            else {
                writeString( format.mid( rxPos, rx.matchedLength() ) );
            };
        };

        nextParam++;
        pos = rxPos + rx.matchedLength();
    };
    
    writeString( format.mid( pos ) );
};

template< typename formaterType >
template< typename T1, typename T2, typename T3 >
void AbstractFormat<formaterType>::printf( const QString& format, T1 p1, T2 p2, T3 p3 ) {
    QRegExp rx( FormatParam::PARAM_PATTERN );
    int nextParam = 1;
    
    if( rx.indexIn( format ) == -1 ) {
        writeString( format );
        return;
    };
    
    int pos = 0;
    int rxPos;
    int curParam;
    while( (rxPos = rx.indexIn( format, pos )) > -1 ) {
        writeString( format.mid( pos, rxPos - pos ) );
        
        if( rx.cap() == FormatParam::PARAM_PREFIX_ESCAPE ) {
            writeString( FormatParam::PARAM_PREFIX_CHAR );
        }
        else {
            FormatParam param( rx );

            curParam = param.getArgIndex();
            if( curParam < 1 ) {
                curParam = nextParam;
            };

            if( curParam == 1 ) {
                writeString( m_Formater.format( m_Locale, param, p1 ) );
            }
            else if( curParam == 2 ) {
                writeString( m_Formater.format( m_Locale, param, p2 ) );
            }
            else if( curParam == 3 ) {
                writeString( m_Formater.format( m_Locale, param, p3 ) );
            }
            else {
                writeString( format.mid( rxPos, rx.matchedLength() ) );
            };
        };

        nextParam++;
        pos = rxPos + rx.matchedLength();
    };
    
    writeString( format.mid( pos ) );
};

template< typename formaterType >
template< typename T1, typename T2, typename T3, typename T4 >
void AbstractFormat<formaterType>::printf( const QString& format, T1 p1, T2 p2, T3 p3, T4 p4 ) {
    QRegExp rx( FormatParam::PARAM_PATTERN );
    int nextParam = 1;
    
    if( rx.indexIn( format ) == -1 ) {
        writeString( format );
        return;
    };
    
    int pos = 0;
    int rxPos;
    int curParam;
    while( (rxPos = rx.indexIn( format, pos )) > -1 ) {
        writeString( format.mid( pos, rxPos - pos ) );
        
        if( rx.cap() == FormatParam::PARAM_PREFIX_ESCAPE ) {
            writeString( FormatParam::PARAM_PREFIX_CHAR );
        }
        else {
            FormatParam param( rx );

            curParam = param.getArgIndex();
            if( curParam < 1 ) {
                curParam = nextParam;
            };

            if( curParam == 1 ) {
                writeString( m_Formater.format( m_Locale, param, p1 ) );
            }
            else if( curParam == 2 ) {
                writeString( m_Formater.format( m_Locale, param, p2 ) );
            }
            else if( curParam == 3 ) {
                writeString( m_Formater.format( m_Locale, param, p3 ) );
            }
            else if( curParam == 4 ) {
                writeString( m_Formater.format( m_Locale, param, p4 ) );
            }
            else {
                writeString( format.mid( rxPos, rx.matchedLength() ) );
            };
        };

        nextParam++;
        pos = rxPos + rx.matchedLength();
    };
    
    writeString( format.mid( pos ) );
};

template< typename formaterType >
template< typename T1, typename T2, typename T3, typename T4, typename T5 >
void AbstractFormat<formaterType>::printf( const QString& format, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5 ) {
    QRegExp rx( FormatParam::PARAM_PATTERN );
    int nextParam = 1;
    
    if( rx.indexIn( format ) == -1 ) {
        writeString( format );
        return;
    };
    
    int pos = 0;
    int rxPos;
    int curParam;
    while( (rxPos = rx.indexIn( format, pos )) > -1 ) {
        writeString( format.mid( pos, rxPos - pos ) );
        
        if( rx.cap() == FormatParam::PARAM_PREFIX_ESCAPE ) {
            writeString( FormatParam::PARAM_PREFIX_CHAR );
        }
        else {
            FormatParam param( rx );

            curParam = param.getArgIndex();
            if( curParam < 1 ) {
                curParam = nextParam;
            };

            if( curParam == 1 ) {
                writeString( m_Formater.format( m_Locale, param, p1 ) );
            }
            else if( curParam == 2 ) {
                writeString( m_Formater.format( m_Locale, param, p2 ) );
            }
            else if( curParam == 3 ) {
                writeString( m_Formater.format( m_Locale, param, p3 ) );
            }
            else if( curParam == 4 ) {
                writeString( m_Formater.format( m_Locale, param, p4 ) );
            }
            else if( curParam == 5 ) {
                writeString( m_Formater.format( m_Locale, param, p5 ) );
            }
            else {
                writeString( format.mid( rxPos, rx.matchedLength() ) );
            };
        };

        nextParam++;
        pos = rxPos + rx.matchedLength();
    };
    
    writeString( format.mid( pos ) );
};

template< typename formaterType >
template< typename T1, typename T2, typename T3, typename T4, typename T5,
            typename T6 >
void AbstractFormat<formaterType>::printf( const QString& format, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5,
                                                    T6 p6 )
{
    QRegExp rx( FormatParam::PARAM_PATTERN );
    int nextParam = 1;
    
    if( rx.indexIn( format ) == -1 ) {
        writeString( format );
        return;
    };
    
    int pos = 0;
    int rxPos;
    int curParam;
    while( (rxPos = rx.indexIn( format, pos )) > -1 ) {
        writeString( format.mid( pos, rxPos - pos ) );
        
        if( rx.cap() == FormatParam::PARAM_PREFIX_ESCAPE ) {
            writeString( FormatParam::PARAM_PREFIX_CHAR );
        }
        else {
            FormatParam param( rx );

            curParam = param.getArgIndex();
            if( curParam < 1 ) {
                curParam = nextParam;
            };

            if( curParam == 1 ) {
                writeString( m_Formater.format( m_Locale, param, p1 ) );
            }
            else if( curParam == 2 ) {
                writeString( m_Formater.format( m_Locale, param, p2 ) );
            }
            else if( curParam == 3 ) {
                writeString( m_Formater.format( m_Locale, param, p3 ) );
            }
            else if( curParam == 4 ) {
                writeString( m_Formater.format( m_Locale, param, p4 ) );
            }
            else if( curParam == 5 ) {
                writeString( m_Formater.format( m_Locale, param, p5 ) );
            }
            else if( curParam == 6 ) {
                writeString( m_Formater.format( m_Locale, param, p6 ) );
            }
            else {
                writeString( format.mid( rxPos, rx.matchedLength() ) );
            };
        };

        nextParam++;
        pos = rxPos + rx.matchedLength();
    };
    
    writeString( format.mid( pos ) );
};

template< typename formaterType >
template< typename T1, typename T2, typename T3, typename T4, typename T5,
            typename T6, typename T7 >
void AbstractFormat<formaterType>::printf( const QString& format, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5,
                                                    T6 p6, T7 p7 )
{
    QRegExp rx( FormatParam::PARAM_PATTERN );
    int nextParam = 1;
    
    if( rx.indexIn( format ) == -1 ) {
        writeString( format );
        return;
    };
    
    int pos = 0;
    int rxPos;
    int curParam;
    while( (rxPos = rx.indexIn( format, pos )) > -1 ) {
        writeString( format.mid( pos, rxPos - pos ) );
        
        if( rx.cap() == FormatParam::PARAM_PREFIX_ESCAPE ) {
            writeString( FormatParam::PARAM_PREFIX_CHAR );
        }
        else {
            FormatParam param( rx );

            curParam = param.getArgIndex();
            if( curParam < 1 ) {
                curParam = nextParam;
            };

            if( curParam == 1 ) {
                writeString( m_Formater.format( m_Locale, param, p1 ) );
            }
            else if( curParam == 2 ) {
                writeString( m_Formater.format( m_Locale, param, p2 ) );
            }
            else if( curParam == 3 ) {
                writeString( m_Formater.format( m_Locale, param, p3 ) );
            }
            else if( curParam == 4 ) {
                writeString( m_Formater.format( m_Locale, param, p4 ) );
            }
            else if( curParam == 5 ) {
                writeString( m_Formater.format( m_Locale, param, p5 ) );
            }
            else if( curParam == 6 ) {
                writeString( m_Formater.format( m_Locale, param, p6 ) );
            }
            else if( curParam == 7 ) {
                writeString( m_Formater.format( m_Locale, param, p7 ) );
            }
            else {
                writeString( format.mid( rxPos, rx.matchedLength() ) );
            };
        };

        nextParam++;
        pos = rxPos + rx.matchedLength();
    };
    
    writeString( format.mid( pos ) );
};

template< typename formaterType >
template< typename T1, typename T2, typename T3, typename T4, typename T5,
            typename T6, typename T7, typename T8 >
void AbstractFormat<formaterType>::printf( const QString& format, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5,
                                                    T6 p6, T7 p7, T8 p8 )
{
    QRegExp rx( FormatParam::PARAM_PATTERN );
    int nextParam = 1;
    
    if( rx.indexIn( format ) == -1 ) {
        writeString( format );
        return;
    };
    
    int pos = 0;
    int rxPos;
    int curParam;
    while( (rxPos = rx.indexIn( format, pos )) > -1 ) {
        writeString( format.mid( pos, rxPos - pos ) );
        
        if( rx.cap() == FormatParam::PARAM_PREFIX_ESCAPE ) {
            writeString( FormatParam::PARAM_PREFIX_CHAR );
        }
        else {
            FormatParam param( rx );

            curParam = param.getArgIndex();
            if( curParam < 1 ) {
                curParam = nextParam;
            };

            if( curParam == 1 ) {
                writeString( m_Formater.format( m_Locale, param, p1 ) );
            }
            else if( curParam == 2 ) {
                writeString( m_Formater.format( m_Locale, param, p2 ) );
            }
            else if( curParam == 3 ) {
                writeString( m_Formater.format( m_Locale, param, p3 ) );
            }
            else if( curParam == 4 ) {
                writeString( m_Formater.format( m_Locale, param, p4 ) );
            }
            else if( curParam == 5 ) {
                writeString( m_Formater.format( m_Locale, param, p5 ) );
            }
            else if( curParam == 6 ) {
                writeString( m_Formater.format( m_Locale, param, p6 ) );
            }
            else if( curParam == 7 ) {
                writeString( m_Formater.format( m_Locale, param, p7 ) );
            }
            else if( curParam == 8 ) {
                writeString( m_Formater.format( m_Locale, param, p8 ) );
            }
            else {
                writeString( format.mid( rxPos, rx.matchedLength() ) );
            };
        };

        nextParam++;
        pos = rxPos + rx.matchedLength();
    };
    
    writeString( format.mid( pos ) );
};

template< typename formaterType >
template< typename T1, typename T2, typename T3, typename T4, typename T5,
            typename T6, typename T7, typename T8, typename T9 >
void AbstractFormat<formaterType>::printf( const QString& format, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5,
                                                    T6 p6, T7 p7, T8 p8, T9 p9 )
{
    QRegExp rx( FormatParam::PARAM_PATTERN );
    int nextParam = 1;
    
    if( rx.indexIn( format ) == -1 ) {
        writeString( format );
        return;
    };
    
    int pos = 0;
    int rxPos;
    int curParam;
    while( (rxPos = rx.indexIn( format, pos )) > -1 ) {
        writeString( format.mid( pos, rxPos - pos ) );
        
        if( rx.cap() == FormatParam::PARAM_PREFIX_ESCAPE ) {
            writeString( FormatParam::PARAM_PREFIX_CHAR );
        }
        else {
            FormatParam param( rx );

            curParam = param.getArgIndex();
            if( curParam < 1 ) {
                curParam = nextParam;
            };

            if( curParam == 1 ) {
                writeString( m_Formater.format( m_Locale, param, p1 ) );
            }
            else if( curParam == 2 ) {
                writeString( m_Formater.format( m_Locale, param, p2 ) );
            }
            else if( curParam == 3 ) {
                writeString( m_Formater.format( m_Locale, param, p3 ) );
            }
            else if( curParam == 4 ) {
                writeString( m_Formater.format( m_Locale, param, p4 ) );
            }
            else if( curParam == 5 ) {
                writeString( m_Formater.format( m_Locale, param, p5 ) );
            }
            else if( curParam == 6 ) {
                writeString( m_Formater.format( m_Locale, param, p6 ) );
            }
            else if( curParam == 7 ) {
                writeString( m_Formater.format( m_Locale, param, p7 ) );
            }
            else if( curParam == 8 ) {
                writeString( m_Formater.format( m_Locale, param, p8 ) );
            }
            else if( curParam == 9 ) {
                writeString( m_Formater.format( m_Locale, param, p9 ) );
            }
            else {
                writeString( format.mid( rxPos, rx.matchedLength() ) );
            };
        };

        nextParam++;
        pos = rxPos + rx.matchedLength();
    };
    
    writeString( format.mid( pos ) );
};

template< typename formaterType >
template< typename T1, typename T2, typename T3, typename T4, typename T5,
            typename T6, typename T7, typename T8, typename T9, typename T10 >
void AbstractFormat<formaterType>::printf( const QString& format, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5,
                                                    T6 p6, T7 p7, T8 p8, T9 p9, T10 p10 )
{
    QRegExp rx( FormatParam::PARAM_PATTERN );
    int nextParam = 1;
    
    if( rx.indexIn( format ) == -1 ) {
        writeString( format );
        return;
    };
    
    int pos = 0;
    int rxPos;
    int curParam;
    while( (rxPos = rx.indexIn( format, pos )) > -1 ) {
        writeString( format.mid( pos, rxPos - pos ) );
        
        if( rx.cap() == FormatParam::PARAM_PREFIX_ESCAPE ) {
            writeString( FormatParam::PARAM_PREFIX_CHAR );
        }
        else {
            FormatParam param( rx );

            curParam = param.getArgIndex();
            if( curParam < 1 ) {
                curParam = nextParam;
            };

            if( curParam == 1 ) {
                writeString( m_Formater.format( m_Locale, param, p1 ) );
            }
            else if( curParam == 2 ) {
                writeString( m_Formater.format( m_Locale, param, p2 ) );
            }
            else if( curParam == 3 ) {
                writeString( m_Formater.format( m_Locale, param, p3 ) );
            }
            else if( curParam == 4 ) {
                writeString( m_Formater.format( m_Locale, param, p4 ) );
            }
            else if( curParam == 5 ) {
                writeString( m_Formater.format( m_Locale, param, p5 ) );
            }
            else if( curParam == 6 ) {
                writeString( m_Formater.format( m_Locale, param, p6 ) );
            }
            else if( curParam == 7 ) {
                writeString( m_Formater.format( m_Locale, param, p7 ) );
            }
            else if( curParam == 8 ) {
                writeString( m_Formater.format( m_Locale, param, p8 ) );
            }
            else if( curParam == 9 ) {
                writeString( m_Formater.format( m_Locale, param, p9 ) );
            }
            else if( curParam == 10 ) {
                writeString( m_Formater.format( m_Locale, param, p10 ) );
            }
            else {
                writeString( format.mid( rxPos, rx.matchedLength() ) );
            };
        };

        nextParam++;
        pos = rxPos + rx.matchedLength();
    };
    
    writeString( format.mid( pos ) );
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
