/***************************************************************************
 *   Copyright (C) 2003-2005 by David Saxton                               *
 *   david@bluehaze.org                                                    *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 ***************************************************************************/

#include "ktechlab.h"
#include "diagnosticstyle.h"
#include "logtofilemsghandler.h"

//#include <dcopclient.h>
#include <kaboutdata.h>
#include <kapplication.h>
#include <kcmdlineargs.h>
#include <kconfig.h>
#include <config.h>
#include <klocalizedstring.h>

static const char description[] =
    I18N_NOOP("An IDE for microcontrollers and electronics");

// static KCmdLineOptions options[] =
// {
//     { "+[URL]", I18N_NOOP( "Document to open." ), 0 },
//     KCmdLineLastOption
// };


int main(int argc, char **argv)
{
    LogToFileMsgHandler logFileHandler;

    KAboutData about(QByteArray("ktechlab"), QByteArray("ktechlab"), ki18n("KTechLab"), VERSION, ki18n(description),
                    KAboutData::License_GPL, ki18n("(C) 2003-2017, The KTechLab developers"),
                    KLocalizedString(), "https://userbase.kde.org/KTechlab", "ktechlab-devel@kde.org" );
	about.addAuthor( ki18n("Alan Grimes"),
                     ki18n("Developer, Simulation"),
                     "" );
	about.addAuthor( ki18n("Zoltan Padrah"),
                     ki18n("Developer") ,
                     QByteArray("zoltan_padrah@users.sourceforge.net"));
    about.addAuthor( ki18n("Julian Bäume"),
                     ki18n("Developer, KDE4 Port, GUI"),
                     QByteArray("julian@svg4all.de") );
    about.addAuthor( ki18n("Juan De Vincenzo"),
                     ki18n("KDE4 Port"),
                     "");
    about.addCredit( ki18n("Lawrence Shafer"),
                     ki18n("Website, wiki and forum"),
                     "");
	about.addCredit( ki18n("Jason Lucas"),
                     ki18n("Keeping up the project during lack of developers"),
                     "" );
	about.addCredit( ki18n("David Saxton"),
                     ki18n("Former developer, project founder, former maintainer"),
                     QByteArray("david@bluehaze.org") );
	about.addCredit( ki18n("Daniel Clarke"),
                     ki18n("Former developer"),
                     QByteArray("daniel.jc@gmail.com") );
	about.addCredit( ki18n("Couriousous"),
                     ki18n("JK flip-flop, asynchronous preset/reset in the D flip-flop"),
                     "" );
	about.addCredit( ki18n("John Myers"),
                     ki18n("Rotary Switch"),
                     "" );
	about.addCredit( ki18n("Ali Akcaagac"),
                     ki18n("Glib friendliness"),
                     "" );
	about.addCredit( ki18n("David Leggett"),
                     ki18n("Former website hosting and feedback during early development"),
                     "" );

    KCmdLineArgs::init(argc, argv, &about);
    KCmdLineOptions options;
    options.add( QByteArray("+[URL]"), ki18n( "Document to open." ), 0);
    KCmdLineArgs::addCmdLineOptions(options);
    KApplication app;

    if (true) {  // TODO add a command line option for debugging the program's visual look
        //app.setStyle(new DiagnosticStyle());
    }
	
    // register ourselves as a dcop client
	//app.dcopClient()->registerAs(app.name(), false);
	
	KTechlab *ktechlab = new KTechlab();
	
	KCmdLineArgs *args = KCmdLineArgs::parsedArgs();
	for ( int i=0; i < args->count(); ++i )
		ktechlab->load( args->url(i) );
	
	ktechlab->show();
	args->clear(); // Free up some memory
	return app.exec();
}
