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
 * This <code>EppResponseDataCheckContact</code> class implements EPP
 * Response Data entity for EPP Command Check of EPP Contact objects.
 *
 * @author Ning Zhang ning.zhang@neustar.com
 * @version $Revision: 1.1 $ $Date: 2005/12/06 20:11:35 $
 */
public class EppResponseDataCheckContact extends EppResponseDataCheck
{
	/**
	 * Checks an <code>EppResponseDataCheckContact</code> object
	 */
	public EppResponseDataCheckContact()
	{
	}

	/**
	 * Converts an XML element into an
	 * <code>EppResponseDataCheckContact</code> object. The caller of this
	 * method must make sure that the root node is the resData element of
	 * EPP responseType for creating an EPP Contact object.
	 *
	 * @param root root node for an
	 *             <code>EppResponseDataCheckContact</code> object
	 *             in XML format
	 *
	 * @return an <code>EppResponseDataCheckContact</code> object, or null
	 *         if the node is invalid
	 */
	public static EppEntity fromXML( Node root )
	{
		EppResponseDataCheckContact rsp = new EppResponseDataCheckContact();
		rsp.fromXMLCommon(root);
		return rsp;
	}

	/**
	 * Converts an <code>EppResponseDataCheckContact</code> object into
	 * an XML element.
	 *
	 * @param doc the XML <code>Document</code> object
	 * @param tag the tag/element name for the
	 *            <code>EppResponseDataCheckContact</code> object
	 *
	 * @return an <code>Element</code> object
	 */
	public Element toXML( Document doc, String tag )
	{
		Element elm;
		Element body = doc.createElement(tag);
		Element data = EppUtil.createElementNS(doc, "contact", "chkData");
		body.appendChild(data);
		toXMLCommon(doc, data);

		return body;
	}
}
