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


#if ! defined(EPPRESPONSEDATACREATECONTACT_HPP)    /* { */
#define       EPPRESPONSEDATACREATECONTACT_HPP        1

#include "EppResponseDataCreate.hpp"

/**
 * This <code>EppResponseDataCreateContact</code> class implements EPP
 * Response Data entity for EPP Command Create of EPP Contact objects.
 *
 * @author Ning Zhang ning.zhang@neustar.com
 * @version $Revision: 1.1 $ $Date: 2005/12/06 20:11:35 $
 */
class EPP_EXPORT EppResponseDataCreateContact : public EppResponseDataCreate
{
private:
	DOMString id;

public:
	/**
	 * Creates an <code>EppResponseDataCreateContact</code> object
	 */
	EppResponseDataCreateContact()
	{
		this->id = null;
	};

	/**
	 * Creates an <code>EppResponseDataCreateContact</code> object,
	 * given the contact id
	 */
	EppResponseDataCreateContact( DOMString id )
	{
		this->id = id;
	};

	/**
	 * Destructor
	 */
	~EppResponseDataCreateContact() {};

	/**
	 * Gets the contact id
	 */
	DOMString getId()
	{
		return this->id;
	};

	/**
	 * Sets the contact id
	 */
	void setId( DOMString id )
	{
		this->id = id;
	};

	/**
	 * Returns the run-time type of an EppEntity object
	 */
	virtual int getEntityType()
	{
		return EppEntity::TYPE_EppResponseDataCreateContact;
	};

	/**
	 * Converts an XML element into an
	 * <code>EppResponseDataCreateContact</code> object. The caller of this
	 * method must make sure that the root node is the resData element of
	 * EPP responseType for creating an EPP Contact object.
	 *
	 * @param root root node for an
	 *             <code>EppResponseDataCreateContact</code> object
	 *             in XML format
	 *
	 * @return an <code>EppResponseDataCreateContact</code> object, or null
	 *         if the node is invalid
	 */
	static EppResponseDataCreateContact * fromXML( const DOM_Node& root );

	/**
	 * Converts an <code>EppResponseDataCreateContact</code> object into
	 * an XML element.
	 *
	 * @param doc the XML <code>DOM_Element</code> object
	 * @param tag the tag/element name for the
	 *            <code>EppResponseDataCreateContact</code> object
	 *
	 * @return an <code>DOM_Element</code> object
	 */
	DOM_Element toXML( DOM_Document& doc, const DOMString& tag );
};

#endif     /* EPPRESPONSEDATACREATECONTACT_HPP */  /* } */
