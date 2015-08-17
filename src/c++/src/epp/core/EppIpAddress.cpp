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
#include "EppIpAddress.hpp"
#include "EppUtil.hpp"

const char * EppIpAddress::TYPE_V4 = "v4";
const char * EppIpAddress::TYPE_V6 = "v6";

DOM_Element EppIpAddress::toXML( DOM_Document& doc, const DOMString& tag )
{
	DOM_Element body = doc.createElement(tag);
	if( ip != null )
	{
		body.setAttribute("ip", ip);
	}
	if( address != null )
	{
		body.appendChild(doc.createTextNode(address));
	}
	return body;
}

EppIpAddress * EppIpAddress::fromXML( const DOM_Node& root )
{
	DOM_Element * elm = (DOM_Element *) &root;
	DOMString address = EppUtil::getText(root);
	DOMString ip = elm->getAttribute("ip");

	return new EppIpAddress(address, ip);
}
