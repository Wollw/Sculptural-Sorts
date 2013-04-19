if &cp | set nocp | endif
let s:cpo_save=&cpo
set cpo&vim
map H <Home>
map J 
map K 
map L <End>
map \gq ?^$\|^\s*\(\\begin\|\\end\|\\label\)?1gq//-1
nmap gx <Plug>NetrwBrowseX
omap lp ?^$\|^\s*\(\\begin\|\\end\|\\label\)?1//-1.
nnoremap <silent> <Plug>NetrwBrowseX :call netrw#NetrwBrowseX(expand("<cWORD>"),0)
nnoremap <F2> :set invpaste paste?
let &cpo=s:cpo_save
unlet s:cpo_save
set backspace=indent,eol,start
set backup
set backupdir=~/.vim/backup///
set clipboard=unnamed
set directory=~/.vim/tmp///
set expandtab
set fileencodings=ucs-bom,utf-8,default,latin1
set helplang=en
set listchars=tab:→\ ,eol:¬
set pastetoggle=<F2>
set ruler
set runtimepath=~/.vim/bundle/vundle,~/.vim/bundle/fsharp-vim,~/.vim/bundle/vim-gitgutter,~/.vim,/usr/share/vim/vimfiles,/usr/share/vim/vim73,/usr/share/vim/vimfiles/after,~/.vim/after,~/.vim/bundle/vundle/,~/.vim/bundle/vundle/after,~/.vim/bundle/fsharp-vim/after,~/.vim/bundle/vim-gitgutter/after
set shiftwidth=4
set suffixes=.bak,~,.swp,.o,.info,.aux,.log,.dvi,.bbl,.blg,.brf,.cb,.ind,.idx,.ilg,.inx,.out,.toc
set tabstop=4
" vim: set ft=vim :
