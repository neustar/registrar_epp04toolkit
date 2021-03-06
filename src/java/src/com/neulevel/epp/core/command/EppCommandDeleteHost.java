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
package com.neulevel.epp.core.command;

import org.w3c.dom.*;
import com.neulevel.epp.core.*;

/**
 * This <code>EppCommandDeleteHost</code> class implements EPP Command Delete
 * entity for EPP Host objects.
 *
 * @author Ning Zhang ning.zhang@neustar.com
 * @version $Revision: 1.1 $ $Date: 2005/12/06 20:11:35 $
 */
public class EppCommandDeleteHost extends EppCommandDelete
{
	private String name;

	/**
	 * Creates an <code>EppCommandDeleteHost</code> object for
	 * deleting a host object based on its name
	 */
	public EppCommandDeleteHost( String name )
	{
		this(name, null);
	}

	/**
	 * Creates an <code>EppCommandDeleteHost</code> object for
	 * deleting a host object based on its name, given a client
	 * transaction id associated with the operation
	 */
	public EppCommandDeleteHost( String name, String xid )
	{
		this.name = name;
		this.clTRID = xid;
	}

	/**
	 * Gets the name of the host object to be deleted
	 */
	public String getName()
	{
		return this.name;
	}

	/**
	 * Sets the name of the host object to be deleted
	 */
	public void setName( String name )
	{
		this.name = name;
	}

	/**
	 * Converts the <code>EppCommandDeleteHost</code> object into an XML
	 * element
	 *
	 * @param doc the XML <code>Document</code> object
	 * @param tag the tag/element name for the
	 *            <code>EppCommandDeleteHost</code> object
	 *
	 * @return an <code>Element</code> object
	 */
	public Element toXML( Document doc, String tag )
	{
		Element elm;
		Element body = EppUtil.createElementNS(doc, "host", tag);

		if( name != null )
		{
			elm = doc.createElement("name");
			elm.appendChild(doc.createTextNode(name));
			body.appendChild(elm);
		}

		return toXMLCommon(doc, tag, body);
	}

	/**
	 * Converts an XML element into an <code>EppCommandDeleteHost</code>
	 * object. The caller of this method must make sure that the root node
	 * is of an EPP Command Delete entity for EPP host object.
	 *
	 * @param root root node for an <code>EppCommandDeleteHost</code>
	 *             object in XML format
	 *
	 * @return an <code>EppCommandDeleteHost</code> object, or null
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
			if( name.equals("name") )
			{
				String s = EppUtil.getText(node);
				return new EppCommandDeleteHost(s);
			}
		}

		return null;
	}
}
