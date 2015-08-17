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
#include "EppResponseDataCheck.hpp"
#include "EppUtil.hpp"

const char * EppResponseDataCheck::UNKNOWN   = " ";
const char * EppResponseDataCheck::FOUND     = "+";
const char * EppResponseDataCheck::NOT_FOUND = "-";

DOMString EppResponseDataCheck::check( DOMString id )
{
	if( this->hashMap != null )
	{
		for( unsigned int i = 0; i < this->hashMap->size(); i++ )
		{
			KeyValuePair<DOMString, DOMString> v = this->hashMap->elementAt(i);
			if( id.equals(v.getKey()) )
			{
				return v.getValue();
			}
		}
	}
	return DOMString(EppResponseDataCheck::UNKNOWN);
}

void EppResponseDataCheck::toXMLCommon( DOM_Document& doc, DOM_Element& body )
{
	DOM_Element elm;
	if( this->hashMap != null )
	{
		for( unsigned int i = 0; i < this->hashMap->size(); i++ )
		{
			KeyValuePair<DOMString, DOMString> v = this->hashMap->elementAt(i);
			elm = doc.createElement("cd");
			elm.setAttribute("x", v.getValue());
			elm.appendChild(doc.createTextNode(v.getKey()));
			body.appendChild(elm);
		}
	}
}

void EppResponseDataCheck::fromXMLCommon( const DOM_Node& root )
{
	DOM_NodeList list = root.getChildNodes();
	for( unsigned int i = 0; i < list.getLength(); i++ )
	{
		DOM_Node node = list.item(i);
		DOMString name = node.getLocalName();
		if( name == null )
		{
			name = node.getNodeName();
		}
		if( name == null )
		{
			continue;
		}
//		if( name.equals("cd") )
		if(    name.equals("cd") || name.equals("contact:cd")
		    || name.equals("domain:cd") || name.equals("host:cd")
		    || name.equals("svcsub:cd") )
		{
			DOM_Element * elm = (DOM_Element *) &node;
			DOMString id = EppUtil::getText(node);
			DOMString cd = elm->getAttribute("x");
			if( (cd != null) && cd.equals(FOUND) )
			{
				this->add(id, cd);
			}
			else if( (cd != null) && cd.equals(NOT_FOUND) )
			{
				this->add(id, cd);
			}
			else
			{
				this->add(id, UNKNOWN);
			}
		}
	}
}