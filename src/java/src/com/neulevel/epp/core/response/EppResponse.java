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

import java.util.*;
import org.w3c.dom.*;
import com.neulevel.epp.core.*;

/**
 * This <code>EppResponse</code> class implements EPP Response entity.
 *
 * @author Ning Zhang ning.zhang@neustar.com
 * @version $Revision: 1.1 $ $Date: 2005/12/06 20:11:35 $
 */
public class EppResponse extends EppEntity
{
	/**
	 * The list of result associated with the EPP Response object, for
	 * a successful operation, the length of the list is one, with an
	 * EPP Result object indicating the completion of an EPP Command.
	 */
	private Vector           result;
	/**
	 * The number of messages remaining in the queue for the client
	 * on the server of the registry
	 */
	private int              msgQCount; // optional
	/**
	 * The timestamp of the message queue updated for the client on
	 * the server of the registry
	 */
	private Calendar         msgQDate; // optional
	/**
	 * The response data related to a sucessful operation
	 */
	private EppResponseData  resData; // optional
	/**
	 * Any extension data associated with the response
	 */
	private EppUnspec        unspec;  // optional
	/**
	 * The Transaction Ids (from both client and server) related to the
	 * response
	 */
	private EppTransactionId trID;

	/**
	 * Gets result
	 */
	public Vector getResult()
	{
		return this.result;
	}

	/**
	 * Adds a result object
	 */
	public void addResult( EppResult result )
	{
		if( this.result == null )
		{
			this.result = new Vector();
		}

		this.result.addElement(result);
	}

	/**
	 * Gets number of messages queued
	 */
	public int getMessageQueued()
	{
		return this.msgQCount;
	}

	/**
	 * Sets number of messages queued
	 */
	public void setMessageQueued( int number )
	{
		this.msgQCount = number;
	}

	/**
	 * Gets the timestamp of the message queue updated by the server
	 */
	public Calendar getMessageQueueUpdated()
	{
		return this.msgQDate;
	}

	/**
	 * Sets the timestamp of the message queue updated by the server
	 */
	public void setMessageQueueUpdated( Calendar cal )
	{
		this.msgQDate = cal;
	}

	/**
	 * Gets response data
	 */
	public EppResponseData getResponseData()
	{
		return this.resData;
	}

	/**
	 * Sets response data
	 */
	public void setResponseData( EppResponseData data )
	{
		this.resData = data;
	}

	/**
	 * Gets optional unspecified object
	 */
	public EppUnspec getUnspec()
	{
		return this.unspec;
	}

	/**
	 * Sets optional unspecified object
	 */
	public void setUnspec( EppUnspec unspec )
	{
		this.unspec = unspec;
	}

	/**
	 * Gets transaction id from the registrar client
	 */
	public EppTransactionId getTransactionId()
	{
		return this.trID;
	}

	/**
	 * Sets transaction id
	 */
	public void setTransactionId( EppTransactionId xid )
	{
		this.trID = xid;
	}

	/**
	 * Checks if the EPP Response is for a completed operation without
	 * any error
	 */
	public boolean success()
	{
		if( result == null )
		{
			return false;
		}

		if( result.size() != 1 )
		{
			return false;
		}

		EppResult r = (EppResult) result.get(0);

		if( EppError.isError(r.getCode()) )
		{
			return false;
		}

		return true;
	}

	/**
	 * Converts the <code>EppResponse</code> object into an XML element
	 *
	 * @param doc the XML <code>Document</code> object
	 * @param tag the tag/element name for the <code>EppResponse</code>
	 *            object
	 *
	 * @return an <code>Element</code> object
	 */
	public Element toXML( Document doc, String tag )
	{
		Element elm;
		Element epp = EppUtil.createElementNS(doc, "epp", null);
		Element body = doc.createElement(tag);
		epp.appendChild(body);

		if( result != null )
		{
			for( int i = 0; i < result.size(); i++ )
			{
				Object obj = (EppResult) result.get(i);
				if( (obj != null) && (obj instanceof EppResult) )
				{
					body.appendChild(((EppResult) obj).toXML(doc, "result"));
				}
			}
		}

		if( (msgQCount > 0) || (msgQDate != null) )
		{
			elm = doc.createElement("msgQ");
			if( msgQCount > 0 )
			{
				elm.setAttribute("count", "" + msgQCount);
			}
			if( msgQDate != null )
			{
				Element d = doc.createElement("qDate");
				d.appendChild(EppUtil.createTextNode(doc, msgQDate));
				elm.appendChild(d);
			}
			body.appendChild(elm);
		}

		if( resData != null )
		{
			body.appendChild(resData.toXML(doc, "resData"));
		}

		if( unspec != null )
		{
			elm = unspec.toXML(doc, "unspec");
			body.appendChild(elm);
		}

		if( trID != null )
		{
			body.appendChild(trID.toXML(doc, "trID"));
		}

		return epp;
	}

	/**
	 * Converts an XML element into an <code>EppResponse</code> object. The
	 * caller of this method must make sure that the root node is of the EPP
	 * responseType.
	 *
	 * @param root root node for an <code>EppResponse</code> object in XML
	 *             format
	 *
	 * @return an <code>EppResponse</code> object, or null if the node is
	 *         invalid
	 */
	public static EppEntity fromXML( Node root )
	{
		EppResponse rsp = null;
		Node response = null;

		NodeList list = root.getChildNodes();
		for( int i = 0; i < list.getLength(); i++ )
		{
			Node node = list.item(i);
			String name = node.getLocalName();
			if( name == null )
			{
				continue;
			}
			if( name.equals("response") )
			{
				response = node;
				break;
			}
		}

		if( response == null )
		{
			return null;
		}

		rsp = new EppResponse();
		list = response.getChildNodes();
		for( int i = 0; i < list.getLength(); i++ )
		{
			Node node = list.item(i);
			String name = node.getLocalName();
			if( name == null )
			{
				continue;
			}
			if( name.equals("result") )
			{
				rsp.addResult((EppResult) EppResult.fromXML(node));
			}
			else if( name.equals("msgQ") )
			{
				String str = ((Element) node).getAttribute("count");
				if( (str != null) && (str.length() > 0) )
				{
					rsp.msgQCount = Integer.parseInt(str);
				}
				NodeList qlist = node.getChildNodes();
				for( int j = 0; j < qlist.getLength(); j++ )
				{
					node = qlist.item(j);
					name = node.getLocalName();
					if( name.equals("qDate") )
					{
						rsp.msgQDate = EppUtil.getDate(node);
					}
				}
			}
			else if( name.equals("resData") )
			{
				rsp.resData = (EppResponseData) EppResponseData.fromXML(node);
			}
			else if( name.equals("unspec") )
			{
				rsp.unspec = (EppUnspec) EppUnspec.fromXML(node);
			}
			else if( name.equals("trID") )
			{
				rsp.trID = (EppTransactionId) EppTransactionId.fromXML(node);
			}
		}

		return rsp;
	}

	public String toString()
	{
		return toString("response");
	}
}
