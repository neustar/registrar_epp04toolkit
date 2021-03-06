/*******************************************************************************
 * The MIT License (MIT)
 *  
 * Copyright (c) 2015 Neustar Inc.
 *  
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *  
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *  
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *******************************************************************************/


#if ! defined(EPPRESULT_HPP)    /* { */
#define       EPPRESULT_HPP        1

#include "EppEntity.hpp"
#include "EppResultMessage.hpp"
#include "EppError.hpp"
#include <util/ValueVectorOf.hpp>

#define	MAX_NUM_OF_RESULT_VALUES	16

/**
 * This <code>EppResult</code> class implements EPP Result entity.
 *
 * @author Ning Zhang ning.zhang@neustar.com
 * @version $Revision: 1.1 $ $Date: 2005/12/06 20:11:35 $
 */
class EPP_EXPORT EppResult : public EppEntity
{
private:
	int                        code;
	EppResultMessage         * msg;
	ValueVectorOf<DOMString> * value;

public:
	/**
	 * Creates an <code>EppResult</code> object
	 */
	EppResult()
	{
		this->code = 0;
		this->msg  = null;
		this->value = new ValueVectorOf<DOMString>(MAX_NUM_OF_RESULT_VALUES);
	};

	/**
	 * Creates an <code>EppResult</code> object
	 *
	 * @param code    result code
	 */
	EppResult( int code )
	{
		this->code = code;
		this->msg  = new EppResultMessage(DOMString(EppError::getText(code)));
		this->value = new ValueVectorOf<DOMString>(MAX_NUM_OF_RESULT_VALUES);
	};

	/**
	 * Creates an <code>EppResult</code> object
	 *
	 * @param code    result code
	 * @param message message to be returned
	 */
	EppResult( int code, DOMString message )
	{
		this->code = code;
		this->msg  = new EppResultMessage(message);
		this->value = new ValueVectorOf<DOMString>(MAX_NUM_OF_RESULT_VALUES);
	};

	/**
	 * Creates an <code>EppResult</code> object
	 *
	 * @param code result code
	 * @param message message to be returned
	 * @param value value to be returned
	 */
	EppResult( int code, DOMString message, DOMString value )
	{
		this->code = code;
		this->msg  = new EppResultMessage(message);
		this->value = new ValueVectorOf<DOMString>(MAX_NUM_OF_RESULT_VALUES);
		this->value->addElement(value);
	};

	/**
	 * Destructor
	 */
	~EppResult()
	{
		if( this->msg != null )
		{
			delete this->msg;
			this->msg = null;
		}
		if( this->value != null )
		{
			delete this->value;
			this->value = null;
		}
	};

	/**
	 * Clones itself, including message and values
	 */
	EppResult * clone();

	/**
	 * Gets result code
	 */
	int getCode()
	{
		return this->code;
	};

	/**
	 * Sets result code
	 */
	void setCode( int code )
	{
		this->code = code;
	};

	/**
	 * Gets message to be returned
	 */
	EppResultMessage * getMessage()
	{
		return this->msg;
	};

	/**
	 * Sets message to be returned
	 */
	void setMessage( DOMString message )
	{
		EppResultMessage m(message);
		this->setMessage(m);
	};

	/**
	 * Sets message to be returned
	 */
	void setMessage( EppResultMessage& message )
	{
		this->setMessage(&message);
	};

	/**
	 * Sets message to be returned
	 */
	void setMessage( EppResultMessage * message );

	/**
	 * Gets values to be returned
	 */
	ValueVectorOf<DOMString> * getValue()
	{
		return this->value;
	};

	/**
	 * Adds values to be returned
	 */
	void addValue( DOMString value )
	{
		this->value->addElement(value);
	};

	/**
	 * Converts the <code>EppResult</code> object into an XML element
	 *
	 * @param doc the XML <code>DOM_Element</code> object
	 * @param tag the tag/element name for the <code>EppResult</code> object
	 *
	 * @return an <code>DOM_Element</code> object
	 */
	DOM_Element toXML( DOM_Document& doc, const DOMString& tag );

	/**
	 * Converts an XML element into an <code>EppResult</code> object. The
	 * caller of this method must make sure that the root node is of the EPP
	 * responseType.
	 *
	 * @param root root node for an <code>EppResult</code> object in XML format
	 *
	 * @return an <code>EppResult</code> object, or null if the node is invalid
	 */
	static EppResult * fromXML( const DOM_Node& root );

	DOMString toString()
	{
		return EppEntity::toString(DOMString("result"));
	};
};

#endif     /* EPPRESULT_HPP */  /* } */
