//-------------------------------------------------------------------------
/*!
    \file scriptobjects.h
    \brief
*/

//-------------------------------------------------------------------------
#ifndef __TOOLKIT_SCRIPT_TEST_SCRIPTOBJECTS_H__
#define __TOOLKIT_SCRIPT_TEST_SCRIPTOBJECTS_H__

// Include Qt Files
#include <QScriptEngine>

//-------------------------------------------------------------------------
/*!
    \brief Implements global functions to be registered in a QScriptEngine
*/
class QtScriptFunctions {
public:
    static QScriptValue arg( QScriptContext*, QScriptEngine* );
};

//-------------------------------------------------------------------------
/*!
    \brief
*/
class QtScriptObject : public QObject {
    Q_OBJECT
    Q_PROPERTY( QString name READ getName WRITE setName )

public:
    static QScriptValue constructor( QScriptContext*, QScriptEngine* );

public:
    //!\name Constructors & Destructor
    //@{
    QtScriptObject();
    virtual ~QtScriptObject();
    //@}

    //!\name Properties
    //@{
    const QString& getName() const;
    void setName( const QString& newName );
    //@}

public slots:
    QString toString() const;
    int getNumber() const;
    void setNumber( int newNumber );

private:
    QString m_Name;
    int m_Number;
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
