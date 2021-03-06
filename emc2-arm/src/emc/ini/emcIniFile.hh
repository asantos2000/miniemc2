/******************************************************************************
 *
 * Copyright (C) 2007 Peter G. Vavaroutsos <pete AT vavaroutsos DOT com>
 *
 * $RCSfile: emcIniFile.hh,v $
 * $Author: petev $
 * $Locker:  $
 * $Revision: 1.4 $
 * $State: Exp $
 * $Date: 2007/06/05 02:54:50 $
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of version 2.1 of the GNU General
 * Public License as published by the Free Software Foundation.
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111 USA
 *
 * THE AUTHORS OF THIS LIBRARY ACCEPT ABSOLUTELY NO LIABILITY FOR
 * ANY HARM OR LOSS RESULTING FROM ITS USE.  IT IS _EXTREMELY_ UNWISE
 * TO RELY ON SOFTWARE ALONE FOR SAFETY.  Any machinery capable of
 * harming persons must have provisions for completely removing power
 * from all motors, etc, before persons enter any danger area.  All
 * machinery must be designed to comply with local and national safety
 * codes, and the authors of this software can not, and do not, take
 * any responsibility for such compliance.
 *
 * This code was written as part of the EMC project.  For more
 * information, go to www.linuxcnc.org.
 *
 ******************************************************************************/

#ifndef _EMCINIFILE_HH_
#define _EMCINIFILE_HH_
 
#include "emc.hh"
#include "inifile.hh"


class EmcIniFile : public IniFile {
public:
                                EmcIniFile(int errMask=0):IniFile(errMask){}

    ErrorCode                   Find(EmcAxisType *result, const char *tag,
                                     const char *section=NULL, int num = 1);
    ErrorCode                   Find(bool *result, const char *tag,
                                     const char *section, int num=1);
    ErrorCode                   FindLinearUnits(EmcLinearUnits *result,
                                                const char *tag,
                                                const char *section=NULL,
                                                int num=1);
    ErrorCode                   FindAngularUnits(EmcAngularUnits *result,
                                                 const char *tag,
                                                 const char *section=NULL,
                                                 int num=1);

    // From base class.
    ErrorCode                   Find(int *result, int min, int max,
                                     const char *tag,const char *section,
                                     int num=1){
                                    return(IniFile::Find(result, min, max,
                                                         tag, section, num));
                                }
    ErrorCode                   Find(int *result, const char *tag,
                                     const char *section=NULL, int num = 1){
                                    return(IniFile::Find(result,
                                                         tag, section, num));
                                }
    ErrorCode                   Find(double *result, double min, double max,
                                     const char *tag,const char *section,
                                     int num=1){
                                    return(IniFile::Find(result, min, max,
                                                         tag, section, num));
                                }
    ErrorCode                   Find(double *result, const char *tag,
                                     const char *section=NULL, int num = 1){
                                    return(IniFile::Find(result,
                                                         tag, section, num));
                                }
    const char *                Find(const char *tag, const char *section=NULL,
                                     int num = 1){
                                    return(IniFile::Find(tag, section, num));
                                }

private:
    static StrIntPair           axisTypeMap[];
    static StrIntPair           boolMap[];
    static StrDoublePair        linearUnitsMap[];
    static StrDoublePair        angularUnitsMap[];
};


#endif
