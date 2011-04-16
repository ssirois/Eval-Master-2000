;****************************************
; Description
;****************************************

; Drush make file for php developpers 

;****************************************
; General
;****************************************

; drush make API version
api = "2"

;****************************************
; Core
;****************************************

core = "6.x"
projects[drupal] = "6.20"

;****************************************
; Translations
;****************************************

; drush dl fr

;****************************************
; Modules from Drupal.org
;****************************************

projects[admin_menu] = "1.6"
projects[admin_menu][subdir] = "contrib"

projects[devel] = "1.23"
projects[devel][subdir] = "contrib"

projects[bueditor] = "2.2"
projects[bueditor][subdir] = "contrib"

projects[cck] = "2.9"
projects[cck][subdir] = "contrib"

projects[views] = "2.12"
projects[views][subdir] = "contrib"

projects[features] = "1.0"
projects[features][subdir] = "contrib"

projects[openidadmin] = "1.2"
projects[openidadmin][subdir] = "contrib"

projects[token] = "1.15"
projects[token][subdir] = "contrib"

projects[ctools] = "1.8"
projects[ctools][subdir] = "contrib"

projects[rules] = "1.4"
projects[rules][subdir] = "contrib"

;****************************************
; Themes from Drupal.org
;****************************************

projects[adaptivetheme] = "2.2"

projects[zen] = "2.1"

;****************************************
; Install Profile
;****************************************

;projects[php_dev][type] = "profile"
;projects[php_dev][download][type] = "git"
;projects[php_dev][download][url] = "git://git.koumbit.net/formation/2010_php.git"
;projects[php_dev][download][branch] = "master"

;****************************************
; End
;****************************************
