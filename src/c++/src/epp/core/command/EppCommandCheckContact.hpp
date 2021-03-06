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

#if ! defined(EPPCOMMANDCHECKCONTACT_HPP)    /* { */
#define       EPPCOMMANDCHECKCONTACT_HPP        1
#include "EppCommandCheck.hpp"

#define	MAX_NUM_OF_CONTACT_IDS	16

/**
 * This <code>EppCommandCheckContact</code> class implements EPP Command Check
 * entity for EPP Contact objects.
 *
 * @author Ning Zhang ning.zhang@neustar.com
 * @version $Revision: 1.1 $ $Date: 2005/12/06 20:11:35 $
 */
class EPP_EXPORT EppCommandCheckContact : public EppCommandCheck
{
private:
	ValueVectorOf<DOMString> * ids;

public:
	/**
	 * Creates an <code>EppCommandCheckContact</code> object
	 */
	EppCommandCheckContact()
	{
		this->ids = new ValueVectorOf<DOMString>(MAX_NUM_OF_CONTACT_IDS);
	};

	/**
	 * Creates an <code>EppCommandCheckContact</code> object, given a
	 * client transaction id associated with the operation
	 */
	EppCommandCheckContact( DOMString xid )
	{
		this->ids = new ValueVectorOf<DOMString>(MAX_NUM_OF_CONTACT_IDS);
		this->clTRID = xid;
	};

	/**
	 * Destructor
	 */
	~EppCommandCheckContact()
	{
		if( this->ids != null )
		{
			delete this->ids;
			this->ids = null;
		}
	};

	/**
	 * Returns the run-time type of an EppEntity object
	 */
	virtual int getEntityType()
	{
		return EppEntity::TYPE_EppCommandCheckContact;
	};

	/**
	 * Gets the list of the ids of the contact objects to be checked
	 */
	ValueVectorOf<DOMString> * getId()
	{
		return this->ids;
	};

	/**
	 * Gets the list of the ids of the contact objects to be checked
	 *
	 * @note this is an alias for <code>getId</code>
	 */
	ValueVectorOf<DOMString> * get()
	{
		return this->getId();
	};

	/**
	 * Adds the id of a contact object to the list of ids of contact
	 * objects be checked
	 */
	void addId( DOMString id )
	{
		this->ids->addElement(id);
	};

	/**
	 * Adds the id of a contact object to the list of ids of contact
	 * objects be checked
	 *
	 * @note this is an alias for <code>addId</code>
	 */
	void add( DOMString id )
	{
		this->addId(id);
	};

	/**
	 * Converts the <code>EppCommandCheckContact</code> object into 
	 * an XML element
	 *
	 * @param doc the XML <code>DOM_Element</code> object
	 * @param tag the tag/element name for the
	 *            <code>EppCommandCheckContact</code> object
	 *
	 * @return an <code>DOM_Element</code> object
	 */
	DOM_Element toXML( DOM_Document& doc, const DOMString& tag );

	/**
	 * Converts an XML element into an <code>EppCommandCheckContact</code>
	 * object. The caller of this method must make sure that the root node
	 * is of an EPP Command Check entity for EPP Contact objects.
	 *
	 * @param root root node for an <code>EppCommandCheckContact</code>
	 *             object in XML format
	 *
	 * @return an <code>EppCommandCheckContact</code> object, or null
	 *         if the node is invalid
	 */
	static EppCommandCheckContact * fromXML( const DOM_Node& root );
};

#endif     /* EPPCOMMANDCHECKCONTACT_HPP */  /* } */
