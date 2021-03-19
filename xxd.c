/*
 *  xxd.c - formatted (like xxd) buffer dump
 *
 *  Written by Ed Rose, Weston Schmidt (2008)
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * -- or --
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
 *
 *  In other words, you are welcome to use, share and improve this program.
 *  You are forbidden to forbid anyone else to use, share and improve
 *  what you give them.   Help stamp out software-hoarding!
 */
#include <stdio.h>

void xxd( const void *buffer, size_t length )
{
    const char hex[17] = "0123456789abcdef";
    char text[16];
    const char *data = (const char *) buffer;
    const char *end = &data[length];
    size_t line = 0;

    while( data < end ) {
        size_t i;
        char *text_ptr = text;

        /* Output the '0000000:' portion */
        putchar( hex[(0x0f & (line >> 24))] );
        putchar( hex[(0x0f & (line >> 20))] );
        putchar( hex[(0x0f & (line >> 16))] );
        putchar( hex[(0x0f & (line >> 12))] );
        putchar( hex[(0x0f & (line >>  8))] );
        putchar( hex[(0x0f & (line >>  4))] );
        putchar( hex[(0x0f & (line      ))] );
        putchar( ':' );
        putchar( ' ' );

        for( i = 0; i < 16; i++ ) {
            if( data < end ) {
                putchar( hex[(0x0f & (*data >> 4))] );
                putchar( hex[(0x0f & (*data))] );
                if( (' ' <= *data) && (*data <= '~') ) {
                    *text_ptr++ = *data;
                } else {
                    *text_ptr++ = '.';
                }
                data++;
            } else {
                putchar( ' ' );
                putchar( ' ' );
                *text_ptr++ = ' ';
            }
            if( 0x01 == (0x01 & i) ) {
                putchar( ' ' );
            }
        }
        line += 16;
        putchar( ' ' );

        for( i = 0; i < 16; i++ ) {
            putchar( text[i] );
        }
        putchar( '\n' );
    }
}
