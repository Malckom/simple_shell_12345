Shells read configuration files in various circumstances. These files usually contain commands for the shell and are executed when loaded; they are usually used to set important variables used to find executables, like $PATH, and others that control the behavior and appearance of the shell. The table in this section shows the configuration files for popular shells.[11]

Configuration file	sh	ksh	csh	tcsh	bash	zsh
/etc/.login			login	login		
/etc/csh.cshrc			yes	yes		
/etc/csh.login			login	login		
~/.tcshrc				yes		
~/.cshrc			yes	yes[a]		
~/etc/ksh.kshrc		int.				
/etc/sh.shrc	int.[b]					
$ENV (typically ~/.kshrc)[12]	int.[c][d]	int.			int.[e]	
~/.login			login	login		
~/.logout			login	login		
/etc/profile	login	login			login	login[f]
~/.profile	login	login			login[g]	login[f]
~/.bash_profile					login[g]	
~/.bash_login					login[g]	
~/.bash_logout					login	
~/.bashrc					int.+n/login	
/etc/zshenv						yes
/etc/zprofile						login
/etc/zshrc						int.
/etc/zlogin						login
/etc/zlogout						login
~/.zshenv						yes
~/.zprofile						login
~/.zshrc						int.
~/.zlogin						login
