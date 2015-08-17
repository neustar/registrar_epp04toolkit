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
package com.neulevel.epp.core.response;

import org.w3c.dom.*;
import com.neulevel.epp.core.*;

/**
 * This <code>EppResponseDataCreateContact</code> class implements EPP
 * Response Data entity for EPP Command Create of EPP Contact objects.
 *
 * @author Ning Zhang ning.zhang@neustar.com
 * @version $Revision: 1.1 $ $Date: 2005/12/06 20:11:35 $
 */
public class EppResponseDataCreateContact extends EppResponseDataCreate
{
	private String id;

	/**
	 * Creates an <code>EppResponseDataCreateContact</code> object,
	 * given the contact id
	 */
	public EppResponseDataCreateContact( String id )
	{
		this.id = id;
	}

	/**
	 * Sets the contact id
	 */
	public void setId( String id )
	{
		this.id = id;
	}

	/**
	 * Gets the contact id
	 */
	public String getId()
	{
		return this.id;
	}

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
	public static EppEntity fromXML( Node root )
	{
		NodeList list = root.getChildNodes();
		for( int i = 0; i < list.getLength(); i++ )
		{
			Node node = list.item(i);
			String name = node.getLocalName();
			if( name == null )
			{
				continue;
			}
			if( name.equals("id") )
			{
				String id = EppUtil.getText(node);
				return new EppResponseDataCreateContact(id);
			}
		}

		return null;
	}

	/**
	 * Converts an <code>EppResponseDataCreateContact</code> object into
	 * an XML element.
	 *
	 * @param doc the XML <code>Document</code> object
	 * @param tag the tag/element name for the
	 *            <code>EppResponseDataCreateContact</code> object
	 *
	 * @return an <code>Element</code> object
	 */
	public Element toXML( Document doc, String tag )
	{
		Element elm;
		Element body = doc.createElement(tag);
		Element data = EppUtil.createElementNS(doc, "contact", "creData");
		body.appendChild(data);
		if( id != null )
		{
			elm = doc.createElement("id");
			elm.appendChild(doc.createTextNode(id));
			data.appendChild(elm);
		}

		return body;
	}
}
