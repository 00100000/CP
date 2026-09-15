# this doesn't actually work as a .sh script right now... I might change that later
# MacOS SIP messes up algo/debug.h every update, so this fixes that

# 1. Install gcc
brew install gcc

# 2. Symlink g++ to gcc instead of clang++ (note that you need to restart your terminal session for this to work)
cd /opt/homebrew/bin/
ln -s g++-16 g++ # (WARNING: Change version of g++ to the version installed in step 1. e.g. 'g++-17')

# alternative:
vi ~/.zshrc
# then paste: (NOT COMMANDS)
alias gcc='gcc-16'
alias cc='gcc-16'
alias g++='g++-16'
alias c++='c++-16'

# 3. Find include path (top non-ignored entry after running this command)
echo | g++ -E -Wp,-v -

# 4. Make algo/debug.h in there
sudo mkdir algo
sudo vi algo/debug.h
# (paste in the algo/debug.h here)
