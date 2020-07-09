/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2019 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#include "protocol.h"

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

      std::string buffer; 

      controlbus.ReadData( buffer ); 

      messageBuffer += buffer;

      auto pos = messageBuffer.find( STARTBYTE );
      if ( std::string::npos == pos )
      {
         messageBuffer.clear(); // no startbyte found
         return false;
      }

      // remove all bytes left from startbyte
      messageBuffer = messageBuffer.substr( pos ); 

      pos = messageBuffer.find( ENDBYTE );
      if ( std::string::npos == pos ) // no endbyte found
      {
         return false;
      }
      
      // copy a full message and remove this message from buffer
      auto protocolString = messageBuffer.substr( 1, pos-1 );
      messageBuffer = messageBuffer.substr( pos+1 );

      pos = protocolString.find( SEPARATOR );
      if ( std::string::npos == pos ) {
         return false;
      }

      // extract key and value 
      attKey = protocolString.substr( 0, pos );
      attValue = protocolString.substr( pos + 1 );

      return true;
   }

   void CProtocol::SendKeyValue( std::string & attKey, std::string & attValue )
   {
      std::string message;
      message = STARTBYTE + attKey + SEPARATOR + attValue + ENDBYTE + LINEBREAK;
      controlbus.WriteData( message );
   }


}
