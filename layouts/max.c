/*
 * max.c - max layout
 *
 * Copyright © 2007 Julien Danjou <julien@danjou.info>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */

#include "tag.h"
#include "screen.h"
#include "util.h"
#include "layouts/max.h"

void
layout_max(awesome_config *awesomeconf)
{
    Client *c;
    ScreenInfo *si = get_screen_info(awesomeconf->display, awesomeconf->screen, &awesomeconf->statusbar, &awesomeconf->padding);

    for(c = *awesomeconf->clients; c; c = c->next)
        if(IS_TILED(c, awesomeconf->screen, awesomeconf->tags, awesomeconf->ntags))
            client_resize(c, si[awesomeconf->screen].x_org, si[awesomeconf->screen].y_org,
                   si[awesomeconf->screen].width - 2 * c->border,
                   si[awesomeconf->screen].height - 2 * c->border, awesomeconf, awesomeconf->resize_hints, False);
    p_delete(&si);
}
// vim: filetype=c:expandtab:shiftwidth=4:tabstop=8:softtabstop=4:encoding=utf-8:textwidth=99
