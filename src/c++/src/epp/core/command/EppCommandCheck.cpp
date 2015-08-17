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
#include "EppCommandCheck.hpp"
#include "EppCommandCheckContact.hpp"
#include "EppCommandCheckDomain.hpp"
#include "EppCommandCheckHost.hpp"
#include "EppCommandCheckSvcsub.hpp"

EppCommandCheck * EppCommandCheck::fromXML( const DOM_Node& root )
{
	DOMString command = root.getLocalName();
	DOM_NodeList list = root.getChildNodes();
	for( unsigned int i = 0; i < list.getLength(); i++ )
	{
		DOM_Node node = list.item(i);
		DOMString prefix = node.getPrefix();
		DOMString name = node.getLocalName();
		if( name == null )
		{
			name = node.getNodeName();
		}
/*
		if( (prefix == null) || (name == null) )
		{
			continue;
		}
		if( name.equals(command) )
		{
			if( prefix.equals("contact") )
			{
				return EppCommandCheckContact.fromXML(node);
			}
			else if( prefix.equals("domain") )
			{
				return EppCommandCheckDomain.fromXML(node);
			}
			else if( prefix.equals("host") )
			{
				return EppCommandCheckHost.fromXML(node);
			}
			else if( prefix.equals("svcsub") )
			{
				return EppCommandCheckSvcsub.fromXML(node);
			}
		}
*/
		if( name.equals("contact:check") )
		{
			return EppCommandCheckContact::fromXML(node);
		}
		else if( name.equals("domain:check") )
		{
			return EppCommandCheckDomain::fromXML(node);
		}
		else if( name.equals("host:check") )
		{
			return EppCommandCheckHost::fromXML(node);
		}
		else if( name.equals("svcsub:check") )
		{
			return EppCommandCheckSvcsub::fromXML(node);
		}
	}

	return null;
}
