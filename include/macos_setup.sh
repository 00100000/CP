# this doesn't actually work as a .sh script right now... I might change that later
# MacOS SIP messes up algo/debug.h every update, so this fixes that

# 1. Install gcc
brew install gcc

# 2. Symlink g++ to gcc instead of clang++
cd /opt/homebrew/bin/
ln -s g++-15 g++ # (WARNING: Change version of g++ to the version installed in step 1. e.g. 'g++-17')

# 3. Find include path (top non-ignored entry after running this command)
echo | g++ -E -Wp,-v -

# 4. Make algo/debug.h in there
sudo mkdir algo
sudo vi algo/debug.h
# (paste in the algo/debug.h here)
