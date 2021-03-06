// license:BSD-3-Clause
// copyright-holders:Miodrag Milanovic
/***************************************************************************

        Orao machine driver by Miodrag Milanovic

        23/02/2008 Sound support added.
        22/02/2008 Preliminary driver.

****************************************************************************/

#include "emu.h"
#include "imagedev/cassette.h"
#include "includes/orao.h"


/* Driver initialization */
void orao_state::init_orao()
{
	memset(m_memory,0xff,0x6000);
}

void orao_state::init_orao103()
{
	memset(m_memory,0xff,0x6000);
}

void orao_state::machine_reset()
{
}

uint8_t orao_state::orao_io_r(offs_t offset)
{
	double level;

		switch(offset) {
		/* Keyboard*/
		case 0x07FC : return m_line[0]->read();
		case 0x07FD : return m_line[1]->read();
		case 0x07FA : return m_line[2]->read();
		case 0x07FB : return m_line[3]->read();
		case 0x07F6 : return m_line[4]->read();
		case 0x07F7 : return m_line[5]->read();
		case 0x07EE : return m_line[6]->read();
		case 0x07EF : return m_line[7]->read();
		case 0x07DE : return m_line[8]->read();
		case 0x07DF : return m_line[9]->read();
		case 0x07BE : return m_line[10]->read();
		case 0x07BF : return m_line[11]->read();
		case 0x077E : return m_line[12]->read();
		case 0x077F : return m_line[13]->read();
		case 0x06FE : return m_line[14]->read();
		case 0x06FF : return m_line[15]->read();
		case 0x05FE : return m_line[16]->read();
		case 0x05FF : return m_line[17]->read();
		case 0x03FE : return m_line[18]->read();
		case 0x03FF : return m_line[19]->read();
		/* Tape */
		case 0x07FF :
					level = m_cassette->input();
					if (level <  0) {
						return 0x00;
					}
					return 0xff;
		}


		return 0xff;
}


void orao_state::orao_io_w(offs_t offset, uint8_t data)
{
	if (offset == 0x0800)
	{
		m_speaker->level_w(m_beep);
		m_cassette->output(m_beep ? 1.0 : -1.0);
		m_beep ^= 1;
	}
}
