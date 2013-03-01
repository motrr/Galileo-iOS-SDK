#!/bin/bash

# Copy over the files from the master branch so we can host the HTML docs #
git merge -X theirs master
git pull -X ours origin gh-pages
git push origin gh-pages