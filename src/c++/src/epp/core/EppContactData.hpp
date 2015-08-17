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


#if ! defined(EPPCONTACTDATA_HPP)    /* { */
#define       EPPCONTACTDATA_HPP        1

#include "EppEntity.hpp"
#include "EppAddress.hpp"

/**
 * This <code>EppContactData</code> class implements EPP Contact multiDataType
 * for recording contact data.
 *
 * @author Ning Zhang ning.zhang@neustar.com
 * @version $Revision: 1.1 $ $Date: 2005/12/06 20:11:35 $
 */
class EPP_EXPORT EppContactData : public EppEntity
{
private:
	DOMString     name;
	DOMString     org;         // optional
	EppAddress    addr;
	bool          hasOrg;      // only used for contact update, default false

public:
	/**
	 * Creates an <code>EppContactData</code> object
	 */
	EppContactData()
	{
		this->name = null;
		this->org = null;
		this->addr = EppAddress();
		this->hasOrg = false;
	};

	/**
	 * Creates an <code>EppContactData</code> object without organization
	 * value
	 *
	 * @param name name of the contact, either a person or a company
	 * @param address address of the contact
	 */
	EppContactData( DOMString name, EppAddress& address )
	{
		this->name = name;
		this->org = null;
		this->addr = address;
		this->hasOrg = false;
	};

	/**
	 * Creates an <code>EppContactData</code> object with organization name
	 *
	 * @param name name of the contact, either a person or a company
	 * @param org name of the organization for the contact
	 * @param address address of the contact
	 */
	EppContactData( DOMString name, DOMString org, EppAddress& address )
	{
		this->name = name;
		this->org  = org;
		this->addr = address;
		this->hasOrg = false;
	};

	/**
	 * Destructor
	 */
	~EppContactData() {};

	/**
	 * Gets the name of the contact
	 */
	DOMString getName()
	{
		return this->name;
	};

	/**
	 * Sets the name of the contact
	 */
	void setName( DOMString name )
	{
		this->name = name;
	};

	/**
	 * Gets the organization name of the contact
	 */
	DOMString getOrganization()
	{
		return this->org;
	};

	/**
	 * Sets the organization name of the contact
	 */
	void setOrganization( DOMString org )
	{
		this->org = org;
	};

	/**
	 * Gets the flag indicating that the organization name should be nullified
	 */
	bool getOrganizationFlag()
	{
		return this->hasOrg;
	};

	/**
	 * Sets the flag indicating that the organization name should be nullified
	 */
	void setOrganizationFlag( bool flag )
	{
		this->hasOrg = flag;
	};

	/**
	 * Gets the address of the contact
	 */
	EppAddress getAddress()
	{
		return this->addr;
	};

	/**
	 * Sets the address of the contact
	 */
	void setAddress( EppAddress& address )
	{
		this->addr = address;
	};

	/**
	 * Converts the <code>EppContactData</code> object into an XML element
	 *
	 * @param doc the XML <code>DOM_Element</code> object
	 * @param tag the tag/element name for the <code>EppContactData</code> object
	 *
	 * @return an <code>DOM_Element</code> object
	 */
	DOM_Element toXML( DOM_Document& doc, const DOMString& tag );

	/**
	 * Converts an XML element into an <code>EppContactData</code> object.
	 * The caller of this method must make sure that the root node is of
	 * the EPP Contact multiDataType.
	 *
	 * @param root root node for an <code>EppContactData</code> object in
	 *             XML format
	 *
	 * @return an <code>EppContactData</code> object, or null if the node is
	 *         invalid
	 */
	static EppContactData * fromXML( const DOM_Node& root );

	DOMString toString()
	{
		return EppEntity::toString(DOMString("contact-data"));
	};
};

#endif     /* EPPCONTACTDATA_HPP */  /* } */
