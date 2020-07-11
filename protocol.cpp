/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2019 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#include "protocol.h"
#include "interface/helper.h"

#include <iostream>

namespace siguni
{

   CProtocol::CProtocol( interface::IControlbus & attControlbus ) 
      : controlbus( attControlbus ) 
   {
   }

   bool CProtocol::GetKeyValue( std::string & attKey, std::string & attValue)
   {
      // if no key or value found, then send empty strings
      attKey.clear(); 
      attValue.clear();
      
      // read bytes to buffer 
      std::string buffer; 
      controlbus.ReadData( buffer ); 

      // add read bytes to internal message buffer
      messageBuffer += buffer;

      // search start byte within messagebuffer, if not found then clear messagebuffer 
      auto pos = messageBuffer.find( STARTBYTE );
      if ( std::string::npos == pos )
      {
         messageBuffer.clear(); 
         return false;
      }

      // remove all bytes left from startbyte
      messageBuffer = messageBuffer.substr( pos ); 

      // search endbyte 
      pos = messageBuffer.find( ENDBYTE );
      if ( std::string::npos == pos ) // no endbyte found
      {
         return false;
      }
      
      // copy a full raw message without start and end byte
      auto protocolString = messageBuffer.substr( 1, pos-1 );

      // remove this message from buffer 
      messageBuffer = messageBuffer.substr( pos+1 );

      // check are there more than one startbytes ?     
      
 
      return helper::CSignalStrings::ExtractKeyValue( 
                     protocolString, SEPARATOR, attKey, attValue ); 

   }

   void CProtocol::SendKeyValue( std::string & attKey, std::string & attValue )
   {
      std::string message;
      message = STARTBYTE + attKey + SEPARATOR + attValue + ENDBYTE + LINEBREAK;
      controlbus.WriteData( message );
   }


}
