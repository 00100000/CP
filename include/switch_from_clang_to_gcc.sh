# 1. Install gcc
brew install gcc

# 2. Symlink g++ to gcc instead of clang++
cd /opt/homebrew/bin/
ln -s g++-14 g++ (WARNING: Change version of g++ to the version installed in step 1. e.g. 'g++-15' instead of 'g++-12')

# 3. Find include path (top non-ignored entry after running this command)
echo | g++ -E -Wp,-v -

# 4. Make algo/debug.h in there
sudo mkdir algo
sudo vi algo/debug.h
(paste in the algo/debug.h here)
