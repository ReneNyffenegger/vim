git checkout master

if (! $?) {
   exit
}

git pull https://github.com/vim/vim

if (! $?) {
   exit
}

git push https://github.com/ReneNyffenegger/vim master

if (! $?) {
   exit
}

git checkout tq84

if (! $?) {
   exit
}

git pull

if (! $?) {
   exit
}

git merge master

if (! $?) {
   exit
}

git push https://github.com/ReneNyffenegger/vim tq84
