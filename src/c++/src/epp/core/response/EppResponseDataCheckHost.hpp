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


#if ! defined(EPPRESPONSEDATACHECKHOST_HPP)    /* { */
#define       EPPRESPONSEDATACHECKHOST_HPP        1

#include "EppResponseDataCheck.hpp"

/**
 * This <code>EppResponseDataCheckHost</code> class implements EPP
 * Response Data entity for EPP Command Check of EPP Host objects.
 *
 * @author Ning Zhang ning.zhang@neustar.com
 * @version $Revision: 1.1 $ $Date: 2005/12/06 20:11:35 $
 */
class EPP_EXPORT EppResponseDataCheckHost : public EppResponseDataCheck
{
public:
	/**
	 * Creates an <code>EppResponseDataCheckHost</code> object
	 */
	EppResponseDataCheckHost() {};

	/**
	 * Destructor
	 */
	~EppResponseDataCheckHost() {};

	/**
	 * Returns the run-time type of an EppEntity object
	 */
	virtual int getEntityType()
	{
		return EppEntity::TYPE_EppResponseDataCheckHost;
	};

	/**
	 * Converts an XML element into an
	 * <code>EppResponseDataCheckHost</code> object. The caller of this
	 * method must make sure that the root node is the resData element of
	 * EPP responseType for creating an EPP Host object.
	 *
	 * @param root root node for an
	 *             <code>EppResponseDataCheckHost</code> object
	 *             in XML format
	 *
	 * @return an <code>EppResponseDataCheckHost</code> object, or null
	 *         if the node is invalid
	 */
	static EppResponseDataCheckHost * fromXML( const DOM_Node& root );

	/**
	 * Converts an <code>EppResponseDataCheckHost</code> object into
	 * an XML element.
	 *
	 * @param doc the XML <code>DOM_Element</code> object
	 * @param tag the tag/element name for the
	 *            <code>EppResponseDataCheckHost</code> object
	 *
	 * @return an <code>DOM_Element</code> object
	 */
	DOM_Element toXML( DOM_Document& doc, const DOMString& tag );
};

#endif     /* EPPRESPONSEDATACHECKHOST_HPP */  /* } */
