/*
  Copyright (C) 2011 spx

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  as published by the Free Software Foundation; either version 2
  of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/

#ifndef _DISABLETHREADLIBRARYCALLS_H_
#define _DISABLETHREADLIBRARYCALLS_H_

// DisableThreadLibraryCalls Function
//   http://msdn.microsoft.com/en-us/library/ms682579.aspx
//
// Note: Do not call "DisableThreadLibraryCalls" in a DLL which is statically linked to the CRT
//   http://support.microsoft.com/kb/555563/en-us

#if defined(_DLL)  /* /MD */

/*
** DllMain
**
** Disables the DLL_THREAD_ATTACH and DLL_THREAD_DETACH notification calls.
**
*/
BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(hinstDLL);
		break;
	}

	return TRUE;
}

#endif

#endif
