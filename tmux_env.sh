#!/usr/bin/env bash
# lab_tmux.sh – start a tmux session for a CS lab

set -euo pipefail
IFS=$'\n\t'

# ------------------------------------------------------------------
# 1. Find or create a tmux session called "lab"
SESSION="lab"

if ! tmux has-session -t "$SESSION" 2>/dev/null; then
    # create a new session detached, no windows yet
    tmux new-session -d -s "$SESSION"
fi

# ------------------------------------------------------------------
# 2. Ask for the lab number
read -p "Enter lab number (e.g., 1, 02, 12): " LABNUM
# Sanitize: remove leading zeros and keep only digits
LABDIR="Lab${LABNUM}"
if [[ ! -d "$LABDIR" ]]; then
    echo "❌ Directory $LABDIR does not exist in $(pwd)."
    exit 1
fi

# ------------------------------------------------------------------
# 3. Set up window #1 (index 0)
tmux rename-window -t "$SESSION:0" "Lab $LABNUM"

# delete any old panes just in case
tmux kill-pane -t "$SESSION:0.*" 2>/dev/null || true

# left half – split vertically, then horizontally
tmux split-window -t "$SESSION:0" -h          # ← right half (nvim)
tmux split-window -t "$SESSION:0.1" -v          # top left (cmake)
tmux select-pane -t "$SESSION:0.1"            # bottom left (todo)

# ------------------------------------------------------------------
# 4. Put commands into each pane
tmux send-keys -t "$SESSION:0.2" "mkdir -p build && cd build && cmake .. && make" C-m
tmux send-keys -t "$SESSION:0.1" "cd $LABDIR && nvim todo.md" C-m
tmux send-keys -t "$SESSION:0.0" "cd $LABDIR && nvim ." C-m

# ------------------------------------------------------------------
# 5. Optional: create a second window that just shows the lab folder
tmux new-window -t "$SESSION" -n "Files"
tmux send-keys -t "$SESSION:1" "cd $LABDIR && ls -al" C-m

# ------------------------------------------------------------------
# 6. Attach to the session (or just detach if you want)
tmux attach-session -t "$SESSION"

