//                              -*- Mode: C++ -*- 
// 
// uC++ Version 7.0.0, Copyright (C) Peter A. Buhr 1994
// 
// NBFile.cc -- 
// 
// Author           : Peter A. Buhr
// Created On       : Tue Apr 27 20:39:18 1993
// Last Modified By : Peter A. Buhr
// Last Modified On : Wed Dec 21 22:13:46 2016
// Update Count     : 25
//
// This  library is free  software; you  can redistribute  it and/or  modify it
// under the terms of the GNU Lesser General Public License as published by the
// Free Software  Foundation; either  version 2.1 of  the License, or  (at your
// option) any later version.
// 
// This library is distributed in the  hope that it will be useful, but WITHOUT
// ANY  WARRANTY;  without even  the  implied  warranty  of MERCHANTABILITY  or
// FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License
// for more details.
// 
// You should  have received a  copy of the  GNU Lesser General  Public License
// along  with this library.
// 

#include <uFile.h>
#include <iostream>
using std::cin;

char ch = '0';						// shared by reader and writer

_Task Reader {
    void main() {
	char tch;

	for ( ;; ) {
	    cin >> tch;					// read number from stdin
	    if ( tch != '\n' ) ch = tch;
	  if ( cin.eof() ) break;
	} // for
    } // Reader::main
}; // Reader

_Task Writer {
    void main() {
	uFile::FileAccess output( "xxx", O_WRONLY | O_CREAT | O_TRUNC, 0666 );
	int i;

	for ( i = 0;; i += 1 ) {
	  if ( cin.eof() ) break;
	    output.write( &ch, 1 );			// write number to stdout
	    yield( 1 );
	} // for
    } // Writer::main
}; // Writer

void uMain::main() {
    Reader reader;
    Writer writer;
} // uMain::main

// Local Variables: //
// compile-command: "u++ NBFile.cc" //
// End: //
