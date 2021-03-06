cbbrowne custom keyboard
==============================

Due to cbbrowne@acm.org
Christopher Browne

This was originally based on the default keyboard map, but I have been
doing sundry experimentation:

1. Useful Experiments
----------------------------------------

 * It made sense to mess around some with keyboard maps.
   - I added a keypad, originally based on keymaps/numpad.c, but
     mighty substantially revised, as that one seems to be rotated 90
     degrees from usual conventions for number pads
 * The keypad layer also includes some sample "hacks" of cool things,
   all using actions attached in using the function action_get_macro()
   - Key [1][2] aka "q" types out my name, cbbrowne, as a fun example
     of a key generating a bunch of keystrokes.  The keystroke is
     sufficiently inconvenient that it isn't terribly practical for me
     to use it, but hey, it shows how others might use this facility
     in a more useful context.
   - Key [2][2] aka "a" uses a random number generator to select a digit 0-9 at random
   - Key [3][2] aka "z" uses a random number generator to select a letter a-z at random
   - Key [1][3] aka "e" spits out the keymap version number
 * Minor use of Space Cadet Shift; my SHIFT key has switched to KC_LSP0, so that when I just hit SHIFT, I get a left parens: ( which is great for Lisping.  I don't have a Right Shift, so I don't get an autoclose; I think I'll live with that until a Planck successor with more lines of keys :-)

2. Some code structure ideas
---------------------------------------------------

   Each layer is given a name to aid in readability, which is then
   used in the keymap matrix below.  The underscores do not denote
   anything - you can have a layer called STUFF or any other name.

   Layer names don't all need to be of the same length, obviously, and
   you could also skip them entirely and just use numbers, though that
   means needing to manage the numbers.

   It is preferable to keep the symbols short so that a line worth of
   key mappings fits compactly onto a line of code.  It might be an
   interesting idea to express the maps rotated 90%, so that you
   only need to fit 4 symbols onto each line, rather than 12.

   I used enums to manage layer IDs and macro IDs so that I don't need
   to care (beyond "start at 0", and arguably that's not needed) about
   their values.

3. Things I did not like about the default mapping
---------------------------------------------------------

   * I found control too hard to get to.  I use it more than Tab, so
     switched it there.
   * Having dash on [lower-j] is a bit nonintuitive, but may be OK
   * I switched ESC/TAB/M(0) around
   * I'm suspicious that I want to shift M(0) from [4][1] to [4][2],
     and shift ESC off the first column so KC_LCTL and KC_LALT can
     be on the first column.
   * I needed to swap ' and ENTER
   * I tried added Workman alongside Dvorak and Colemak
     - Boy, oh boy, these don't help!!!
     - I have done 30 years of learning of Emacs key mappings, and
       these alternative keyboards massively mess me up

4. TODO
---------------------------------------------------------

  * I use tmux quite a lot; the mollat keymap seems to have some
    interesting helpers.  It might be interesting to add a "tmux
    layer," or to have a few keys in a layer oriented towards that
  * The mollat tmux layer also suggests some thoughts about Emacs
    helpers.
  * I do not presently have anything that handles X11 screen
    switching, as with Control-Alt-various
  * I ought to probably look into KC_LEAD, to have some key combos
    that do not need to be concurrent
  * The jeebak keymap seems to have some neat ideas:
    - Number layer which is aggressive about having numbers in several places
    - Touch layer seems interesting
  * Trying out sgoodwin's "hold Enter down to get Shift"