# Test Results for SmallThinker Models

0.5b without spec:

```
/home/shuojiang/New-Projects/Attempt2/PowerServe/cmake-build-debug/bin/run --work-folder /home/shuojiang/New-Projects/Attempt2/PowerServe/models/ --model smallthinker-0.5b --thread 4 --prompt "Please introduce the company NIO." --no-qnn
[INFO ] Compiled on: Feb  4 2025 at 10:51:34
[INFO ] Load model qwen2 ...
[INFO ] after model init: [Memory(MB)] VMS: 664, RSS: 660
[INFO ] after platform init: [Memory(MB)] VMS: 1432, RSS: 660
[INFO ] after attn init: [Memory(MB)] VMS: 1432, RSS: 660
[DEBUG] special_bos         : 151643: <|endoftext|>
[DEBUG] special_eos         : 151645: <|im_end|>
[DEBUG] special_pad         : 151643: <|endoftext|>
[DEBUG] special_eot         : 151645: <|im_end|>
[INFO ] after tokenizer init: [Memory(MB)] VMS: 1482, RSS: 711
[INFO ] seed: 0
[INFO ] after sampler init: [Memory(MB)] VMS: 1482, RSS: 711
[INFO ] prompt      : "Please introduce the company NIO."
[INFO ] n_predicts  : 16
[INFO ] model arch  : qwen2
[INFO ] n_threads   : 4
[INFO ] batch_size   : 128
Please introduce the company NIO.
Not bug here1......
Not bug here4......
 loop 1:  loop 2:  N loop 3: IO loop 4:  is loop 5:  a loop 6:  leading loop 7:  provider loop 8:  of loop 9:  innovative loop 10:  solutions loop 11:  for loop 12:  the loop 13:  Internet loop 14:  of loop 15:  Things loop 16:  (
[INFO ] prefill time: 0.866 s
[INFO ] prefill speed (6 tokens): 6.928406466512702 tokens/s
[INFO ] decode speed (15 tokens): 4.191114836546522 tokens/s
[INFO ] total speed: 4.724409448818897 tokens/s

Process finished with exit code 0
```

3b without spec:

```
/home/shuojiang/New-Projects/Attempt2/PowerServe/cmake-build-debug/bin/run --work-folder /home/shuojiang/New-Projects/Attempt2/PowerServe/models/ --model smallthinker-3b --thread 4 --prompt "Please introduce the company NIO." --no-qnn
[INFO ] Compiled on: Feb  4 2025 at 10:51:34
[INFO ] Load model qwen2 ...
[INFO ] after model init: [Memory(MB)] VMS: 3468, RSS: 3464
[INFO ] after platform init: [Memory(MB)] VMS: 5773, RSS: 3464
[INFO ] after attn init: [Memory(MB)] VMS: 5773, RSS: 3464
[DEBUG] special_bos         : 151643: <|endoftext|>
[DEBUG] special_eos         : 151645: <|im_end|>
[DEBUG] special_pad         : 151643: <|endoftext|>
[DEBUG] special_eot         : 151645: <|im_end|>
[INFO ] after tokenizer init: [Memory(MB)] VMS: 5823, RSS: 3515
[INFO ] seed: 0
[INFO ] after sampler init: [Memory(MB)] VMS: 5823, RSS: 3515
[INFO ] prompt      : "Please introduce the company NIO."
[INFO ] n_predicts  : 16
[INFO ] model arch  : qwen2
[INFO ] n_threads   : 4
[INFO ] batch_size   : 128
Please introduce the company NIO.
Not bug here1......
Not bug here4......
 loop 1:  loop 2:  N loop 3: IO loop 4:  is loop 5:  a loop 6:  Chinese loop 7:  electric loop 8:  vehicle loop 9:  manufacturer loop 10:  based loop 11:  in loop 12:  Shanghai loop 13: , loop 14:  China loop 15: . loop 16:  Founded
[INFO ] prefill time: 6.344 s
[INFO ] prefill speed (6 tokens): 0.9457755359394704 tokens/s
[INFO ] decode speed (15 tokens): 0.805325888542897 tokens/s
[INFO ] total speed: 0.841009211053264 tokens/s

Process finished with exit code 0
```

spec test 01:

```
/home/shuojiang/New-Projects/Attempt2/PowerServe/cmake-build-debug/bin/run --work-folder /home/shuojiang/New-Projects/Attempt2/PowerServe/models/ --model smallthinker-3b --draft-model smallthinker-0.5b --thread 4 --prompt "Please introduce the company NIO." --no-qnn
[INFO ] Compiled on: Feb  4 2025 at 10:59:45
[INFO ] Load model qwen2 ...
[INFO ] Load model qwen2 ...
[INFO ] after model init: [Memory(MB)] VMS: 4122, RSS: 4118
[INFO ] after platform init: [Memory(MB)] VMS: 7195, RSS: 4118
[INFO ] after attn init: [Memory(MB)] VMS: 7195, RSS: 4118
[DEBUG] special_bos         : 151643: <|endoftext|>
[DEBUG] special_eos         : 151645: <|im_end|>
[DEBUG] special_pad         : 151643: <|endoftext|>
[DEBUG] special_eot         : 151645: <|im_end|>
[INFO ] after tokenizer init: [Memory(MB)] VMS: 7245, RSS: 4169
[INFO ] seed: 0
[INFO ] after sampler init: [Memory(MB)] VMS: 7245, RSS: 4169
[INFO ] prompt      : "Please introduce the company NIO."
[INFO ] n_predicts  : 16
[INFO ] model arch  : qwen2
[INFO ] n_threads   : 4
[INFO ] batch_size   : 128
Please introduce the company NIO.
Not bug here1......
Not bug here2......
no bug inside 1......
no bug inside 2......
target model id: smallthinker_3b
no bug inside 2.3......
draft model id: smallthinker_500m
no bug inside 2.4......
no bug inside 2.5......
no bug inside 3......
no bug inside 4......
no bug inside 5......
no bug inside 6......
Not bug here3......
Not bug here4......
 loop 1:  loop 2:  N loop 3: IO loop 4: IO loop 5:  Resources loop 6:  Co loop 7:  Resources loop 8:  Co loop 9:  Ltd loop 10:  Co loop 11: ., loop 12: 

 loop 13:  Resources loop 14: 

 loop 15: N loop 16:  Resources
[INFO ] prefill time: 13.028 s
[INFO ] prefill speed (6 tokens): 0.460546515198035 tokens/s
[INFO ] decode speed (15 tokens): 0.04263313617876358 tokens/s
[INFO ] total speed: 0.057555218750942126 tokens/s
Speculative token tree statistics:
- 13 iterations, 18 generated tokens
- 1.385 tokens/iteration
- 6.769 draft-forwards/iteration
- Accept ratio: 3.650%
- Draft effective ratio: 5.682%

Process finished with exit code 0
```

with tree debug info:

```
/home/shuojiang/New-Projects/Attempt2/PowerServe/cmake-build-debug/bin/run --work-folder /home/shuojiang/New-Projects/Attempt2/PowerServe/models/ --model smallthinker-3b --draft-model smallthinker-0.5b --thread 4 --prompt "Please introduce the company NIO." --no-qnn
[INFO ] Compiled on: Feb  4 2025 at 11:33:14
[INFO ] Load model qwen2 ...
[INFO ] Load model qwen2 ...
[INFO ] after model init: [Memory(MB)] VMS: 4122, RSS: 4118
[INFO ] after platform init: [Memory(MB)] VMS: 7195, RSS: 4118
[INFO ] after attn init: [Memory(MB)] VMS: 7195, RSS: 4118
[DEBUG] special_bos         : 151643: <|endoftext|>
[DEBUG] special_eos         : 151645: <|im_end|>
[DEBUG] special_pad         : 151643: <|endoftext|>
[DEBUG] special_eot         : 151645: <|im_end|>
[INFO ] after tokenizer init: [Memory(MB)] VMS: 7245, RSS: 4169
[INFO ] seed: 0
[INFO ] after sampler init: [Memory(MB)] VMS: 7245, RSS: 4169
[INFO ] prompt      : "Please introduce the company NIO."
[INFO ] n_predicts  : 16
[INFO ] model arch  : qwen2
[INFO ] n_threads   : 4
[INFO ] batch_size   : 128
Please introduce the company NIO.
Not bug here1......
Not bug here2......
no bug inside 1......
no bug inside 2......
target model id: smallthinker_3b
no bug inside 2.3......
draft model id: smallthinker_500m
no bug inside 2.4......
no bug inside 2.5......
no bug inside 3......
no bug inside 4......
no bug inside 5......
no bug inside 6......
Not bug here3......
Not bug here4......
 loop 1: 
=================================================================
[*] "." 1.00
 [*] " N" 0.84
  [*] "IO" 0.99
   [ ] " is" 0.88
    [ ] " a" 0.84
     [ ] " leading" 0.73
      [ ] " provider" 0.54
       [ ] " of" 0.98
        [ ] " innovative" 0.68
      [ ] " technology" 0.46
     [ ] " company" 0.27
 [ ] " I" 0.16
 loop 2:  N loop 3: IO loop 4: 
=================================================================
[*] "IO" 1.00
 [ ] " is" 0.75
  [ ] " a" 0.75
   [ ] " leading" 0.54
    [ ] " provider" 0.60
    [ ] " technology" 0.40
   [ ] " company" 0.46
  [ ] " the" 0.25
 [ ] "," 0.25
IO loop 5: 
=================================================================
[*] " Resources" 1.00
 [ ] " is" 0.72
  [ ] " a" 0.80
   [ ] " leading" 0.67
    [ ] " provider" 0.76
     [ ] " of" 0.96
      [ ] " innovative" 0.67
      [ ] " high" 0.33
    [ ] " global" 0.24
   [ ] " company" 0.33
  [ ] " the" 0.20
 [ ] "," 0.28
 Resources loop 6: 
=================================================================
[*] " Co" 1.00
 [ ] "." 0.59
  [ ] " Ltd" 0.78
   [ ] "." 0.71
    [ ] " is" 0.69
     [ ] " a" 0.87
     [ ] " an" 0.13
    [ ] " (" 0.31
   [ ] ".," 0.29
  [ ] " is" 0.22
 [ ] ".," 0.41
 Co loop 7: 
=================================================================
[*] " Resources" 1.00
 [ ] " is" 0.52
  [ ] " a" 0.85
   [ ] " leading" 0.62
    [ ] " provider" 0.61
    [ ] " global" 0.39
   [ ] " company" 0.38
 [ ] " Inc" 0.48
  [ ] "." 0.52
   [ ] " N" 0.59
  [ ] " Resources" 0.48
   [ ] " Inc" 0.66
 Resources loop 8: 
=================================================================
[*] " Co" 1.00
 [ ] " Resources" 0.72
  [ ] " Co" 0.86
   [ ] " Resources" 0.71
    [ ] " Co" 0.94
     [ ] " Resources" 0.73
      [ ] " Co" 0.95
       [ ] " Resources" 0.79
        [ ] " Co" 0.95
         [ ] " Resources" 0.86
   [ ] "\n\n" 0.29
 [*] " Ltd" 0.28
 Co loop 9:  Ltd loop 10: 
=================================================================
[*] " Co" 1.00
 [ ] " Ltd" 0.56
  [ ] " Co" 0.75
   [ ] " Ltd" 0.87
    [ ] " Co" 0.77
     [ ] " Ltd" 0.91
      [ ] " Co" 0.80
       [ ] " Ltd" 0.92
    [ ] "\n\n" 0.23
   [ ] " Co" 0.13
  [ ] " N" 0.25
 [ ] " Resources" 0.44
 Co loop 11: 
=================================================================
[*] ".," 1.00
 [ ] " Ltd" 0.84
  [ ] "." 0.66
   [ ] " N" 0.69
    [ ] "IO" 0.97
     [ ] "IO" 0.55
      [ ] " Resources" 0.95
     [ ] "," 0.45
    [ ] "io" 0.03
   [ ] " is" 0.31
  [ ] ".\n\n" 0.34
 [ ] " a" 0.16
., loop 12: 
=================================================================
[*] "\n\n" 1.00
 [ ] "N" 0.55
  [ ] "IO" 0.98
   [ ] " is" 0.55
    [ ] " a" 0.85
     [ ] " leading" 0.70
     [ ] " company" 0.30
    [ ] " an" 0.15
   [ ] "IO" 0.45
  [ ] "io" 0.02
 [ ] "So" 0.45


 loop 13: 
=================================================================
[*] " Resources" 1.00
 [ ] " Co" 0.94
  [ ] " Resources" 0.65
   [ ] " Co" 0.90
    [ ] " Ltd" 0.90
     [ ] " Co" 0.58
      [ ] ".," 0.72
       [ ] " N" 0.55
       [ ] "\n\n" 0.45
      [ ] "." 0.28
     [ ] "," 0.42
  [ ] " Ltd" 0.35
 Resources loop 14: 
=================================================================
[*] "\n\n" 1.00
 [ ] " Resources" 0.51
  [ ] "\n\n" 0.88
   [ ] " N" 0.75
    [ ] "IO" 0.92
     [ ] "\n\n" 0.65
      [ ] " company" 0.70
 [ ] " N" 0.49
  [ ] "IO" 0.99
   [ ] " is" 0.54
    [ ] " a" 0.88
     [ ] " leading" 0.71


 loop 15: 
=================================================================
[*] "N" 1.00
 [ ] "IO" 0.99
  [ ] " is" 0.53
   [ ] " a" 0.87
    [ ] " leading" 0.70
     [ ] " provider" 0.53
     [ ] " technology" 0.47
    [ ] " company" 0.30
   [ ] " an" 0.13
  [ ] "IO" 0.47
 [ ] "io" 0.01
N loop 16: 
=================================================================
[*] " Resources" 1.00
 [*] "\n\n" 0.51
  [*] "N" 0.70
   [ ] "IO" 0.89
    [ ] " Resources" 0.72
     [ ] " Co" 0.75
 [ ] " Co" 0.49
  [ ] " Resources" 0.61
   [ ] " Co" 0.77
    [ ] " Ltd" 0.90
     [ ] " Co" 0.67
  [ ] " Ltd" 0.39
 Resources
[INFO ] prefill time: 13.574 s
[INFO ] prefill speed (6 tokens): 0.44202151171357007 tokens/s
[INFO ] decode speed (15 tokens): 0.044465524396751055 tokens/s
[INFO ] total speed: 0.05984372239352092 tokens/s
Speculative token tree statistics:
- 13 iterations, 18 generated tokens
- 1.385 tokens/iteration
- 6.769 draft-forwards/iteration
- Accept ratio: 3.650%
- Draft effective ratio: 5.682%

Process finished with exit code 0
```

More debugs:

```
/home/shuojiang/New-Projects/Attempt2/PowerServe/cmake-build-debug/bin/run --work-folder /home/shuojiang/New-Projects/Attempt2/PowerServe/models/ --model smallthinker-3b --draft-model smallthinker-0.5b --thread 4 --prompt "Please introduce the company NIO." --no-qnn
[INFO ] Compiled on: Feb  4 2025 at 11:33:14
[INFO ] Load model qwen2 ...
[INFO ] Load model qwen2 ...
[INFO ] after model init: [Memory(MB)] VMS: 4122, RSS: 4118
[INFO ] after platform init: [Memory(MB)] VMS: 7195, RSS: 4119
[INFO ] after attn init: [Memory(MB)] VMS: 7195, RSS: 4119
[DEBUG] special_bos         : 151643: <|endoftext|>
[DEBUG] special_eos         : 151645: <|im_end|>
[DEBUG] special_pad         : 151643: <|endoftext|>
[DEBUG] special_eot         : 151645: <|im_end|>
[INFO ] after tokenizer init: [Memory(MB)] VMS: 7245, RSS: 4169
[INFO ] seed: 0
[INFO ] after sampler init: [Memory(MB)] VMS: 7245, RSS: 4169
[INFO ] prompt      : "Please introduce the company NIO."
[INFO ] n_predicts  : 16
[INFO ] model arch  : qwen2
[INFO ] n_threads   : 4
[INFO ] batch_size   : 128
Please introduce the company NIO.
Not bug here1......
Not bug here2......
no bug inside 1......
no bug inside 2......
target model id: smallthinker_3b
no bug inside 2.3......
draft model id: smallthinker_500m
no bug inside 2.4......
no bug inside 2.5......
no bug inside 3......
no bug inside 4......
no bug inside 5......
no bug inside 6......
Not bug here3......
Not bug here4......
 *******************************************************************OUTER LOOP 1:******************************************************************** 
(Inside TokenIterator::next()) The next token is: . (#13)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 1
 (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is: . (#13)
            (Inside TokenTree::draft()) Start forwarding in draft model: time 1
            (Inside TokenTree::draft()) Start forwarding in draft model: time 2
            (Inside TokenTree::draft()) Start forwarding in draft model: time 3
            (Inside TokenTree::draft()) Start forwarding in draft model: time 4
            (Inside TokenTree::draft()) Start forwarding in draft model: time 5
            (Inside TokenTree::draft()) Start forwarding in draft model: time 6
            (Inside TokenTree::draft()) Start forwarding in draft model: time 7
            (Inside TokenTree::draft()) Start forwarding in draft model: time 8
            (Inside TokenTree::draft()) n_saved_tokens: 8; n_nodes: 12

===================================DEBUG TOKEN TREE START====================================
[ACC] "." 1.00
 [ACC] " N" 0.84
  [ACC] "IO" 0.99
   [REJ] " is" 0.88
    [REJ] " a" 0.84
     [REJ] " leading" 0.73
      [REJ] " provider" 0.54
       [REJ] " of" 0.98
        [REJ] " innovative" 0.68
      [REJ] " technology" 0.46
     [REJ] " company" 0.27
 [REJ] " I" 0.16

===================================DEBUG TOKEN TREE END====================================
     (Inside SpecTokenIterator::decode()) token queue:   N (#451),  IO (#3810),  IO (#3810), 
 *******************************************************************OUTER LOOP 2:******************************************************************** 
(Inside TokenIterator::next()) The next token is:  N (#451)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 3

^^^^^^^^^^^^^^^^^^^TEXT:  N (#451)^^^^^^^^^^^^^^^^^^^
 *******************************************************************OUTER LOOP 3:******************************************************************** 
(Inside TokenIterator::next()) The next token is: IO (#3810)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 2

^^^^^^^^^^^^^^^^^^^TEXT: IO (#3810)^^^^^^^^^^^^^^^^^^^
 *******************************************************************OUTER LOOP 4:******************************************************************** 
(Inside TokenIterator::next()) The next token is: IO (#3810)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 1
 (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is: IO (#3810)
            (Inside TokenTree::draft()) Start forwarding in draft model: time 1
            (Inside TokenTree::draft()) Start forwarding in draft model: time 2
            (Inside TokenTree::draft()) Start forwarding in draft model: time 3
            (Inside TokenTree::draft()) Start forwarding in draft model: time 4
            (Inside TokenTree::draft()) n_saved_tokens: 4; n_nodes: 9

===================================DEBUG TOKEN TREE START====================================
[ACC] "IO" 1.00
 [REJ] " is" 0.75
  [REJ] " a" 0.75
   [REJ] " leading" 0.54
    [REJ] " provider" 0.60
    [REJ] " technology" 0.40
   [REJ] " company" 0.46
  [REJ] " the" 0.25
 [REJ] "," 0.25

===================================DEBUG TOKEN TREE END====================================
     (Inside SpecTokenIterator::decode()) token queue:   Resources (#16209), 

^^^^^^^^^^^^^^^^^^^TEXT: IO (#3810)^^^^^^^^^^^^^^^^^^^
 *******************************************************************OUTER LOOP 5:******************************************************************** 
(Inside TokenIterator::next()) The next token is:  Resources (#16209)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 1
 (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is:  Resources (#16209)
            (Inside TokenTree::draft()) Start forwarding in draft model: time 1
            (Inside TokenTree::draft()) Start forwarding in draft model: time 2
            (Inside TokenTree::draft()) Start forwarding in draft model: time 3
            (Inside TokenTree::draft()) Start forwarding in draft model: time 4
            (Inside TokenTree::draft()) Start forwarding in draft model: time 5
            (Inside TokenTree::draft()) Start forwarding in draft model: time 6
            (Inside TokenTree::draft()) n_saved_tokens: 6; n_nodes: 12

===================================DEBUG TOKEN TREE START====================================
[ACC] " Resources" 1.00
 [REJ] " is" 0.72
  [REJ] " a" 0.80
   [REJ] " leading" 0.67
    [REJ] " provider" 0.76
     [REJ] " of" 0.96
      [REJ] " innovative" 0.67
      [REJ] " high" 0.33
    [REJ] " global" 0.24
   [REJ] " company" 0.33
  [REJ] " the" 0.20
 [REJ] "," 0.28

===================================DEBUG TOKEN TREE END====================================
     (Inside SpecTokenIterator::decode()) token queue:   Co (#3539), 

^^^^^^^^^^^^^^^^^^^TEXT:  Resources (#16209)^^^^^^^^^^^^^^^^^^^
 *******************************************************************OUTER LOOP 6:******************************************************************** 
(Inside TokenIterator::next()) The next token is:  Co (#3539)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 1
 (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is:  Co (#3539)
            (Inside TokenTree::draft()) Start forwarding in draft model: time 1
            (Inside TokenTree::draft()) Start forwarding in draft model: time 2
            (Inside TokenTree::draft()) Start forwarding in draft model: time 3
            (Inside TokenTree::draft()) Start forwarding in draft model: time 4
            (Inside TokenTree::draft()) Start forwarding in draft model: time 5
            (Inside TokenTree::draft()) n_saved_tokens: 5; n_nodes: 11

===================================DEBUG TOKEN TREE START====================================
[ACC] " Co" 1.00
 [REJ] "." 0.59
  [REJ] " Ltd" 0.78
   [REJ] "." 0.71
    [REJ] " is" 0.69
     [REJ] " a" 0.87
     [REJ] " an" 0.13
    [REJ] " (" 0.31
   [REJ] ".," 0.29
  [REJ] " is" 0.22
 [REJ] ".," 0.41

===================================DEBUG TOKEN TREE END====================================
     (Inside SpecTokenIterator::decode()) token queue:   Resources (#16209), 

^^^^^^^^^^^^^^^^^^^TEXT:  Co (#3539)^^^^^^^^^^^^^^^^^^^
 *******************************************************************OUTER LOOP 7:******************************************************************** 
(Inside TokenIterator::next()) The next token is:  Resources (#16209)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 1
 (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is:  Resources (#16209)
            (Inside TokenTree::draft()) Start forwarding in draft model: time 1
            (Inside TokenTree::draft()) Start forwarding in draft model: time 2
            (Inside TokenTree::draft()) Start forwarding in draft model: time 3
            (Inside TokenTree::draft()) Start forwarding in draft model: time 4
            (Inside TokenTree::draft()) Start forwarding in draft model: time 5
            (Inside TokenTree::draft()) Start forwarding in draft model: time 6
            (Inside TokenTree::draft()) Start forwarding in draft model: time 7
            (Inside TokenTree::draft()) n_saved_tokens: 7; n_nodes: 12

===================================DEBUG TOKEN TREE START====================================
[ACC] " Resources" 1.00
 [REJ] " is" 0.52
  [REJ] " a" 0.85
   [REJ] " leading" 0.62
    [REJ] " provider" 0.61
    [REJ] " global" 0.39
   [REJ] " company" 0.38
 [REJ] " Inc" 0.48
  [REJ] "." 0.52
   [REJ] " N" 0.59
  [REJ] " Resources" 0.48
   [REJ] " Inc" 0.66

===================================DEBUG TOKEN TREE END====================================
     (Inside SpecTokenIterator::decode()) token queue:   Co (#3539), 

^^^^^^^^^^^^^^^^^^^TEXT:  Resources (#16209)^^^^^^^^^^^^^^^^^^^
 *******************************************************************OUTER LOOP 8:******************************************************************** 
(Inside TokenIterator::next()) The next token is:  Co (#3539)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 1
 (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is:  Co (#3539)
            (Inside TokenTree::draft()) Start forwarding in draft model: time 1
            (Inside TokenTree::draft()) Start forwarding in draft model: time 2
            (Inside TokenTree::draft()) Start forwarding in draft model: time 3
            (Inside TokenTree::draft()) Start forwarding in draft model: time 4
            (Inside TokenTree::draft()) Start forwarding in draft model: time 5
            (Inside TokenTree::draft()) Start forwarding in draft model: time 6
            (Inside TokenTree::draft()) Start forwarding in draft model: time 7
            (Inside TokenTree::draft()) Start forwarding in draft model: time 8
            (Inside TokenTree::draft()) Start forwarding in draft model: time 9
            (Inside TokenTree::draft()) n_saved_tokens: 9; n_nodes: 12

===================================DEBUG TOKEN TREE START====================================
[ACC] " Co" 1.00
 [REJ] " Resources" 0.72
  [REJ] " Co" 0.86
   [REJ] " Resources" 0.71
    [REJ] " Co" 0.94
     [REJ] " Resources" 0.73
      [REJ] " Co" 0.95
       [REJ] " Resources" 0.79
        [REJ] " Co" 0.95
         [REJ] " Resources" 0.86
   [REJ] "\n\n" 0.29
 [ACC] " Ltd" 0.28

===================================DEBUG TOKEN TREE END====================================
     (Inside SpecTokenIterator::decode()) token queue:   Ltd (#12324),   Co (#3539), 

^^^^^^^^^^^^^^^^^^^TEXT:  Co (#3539)^^^^^^^^^^^^^^^^^^^
 *******************************************************************OUTER LOOP 9:******************************************************************** 
(Inside TokenIterator::next()) The next token is:  Ltd (#12324)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 2

^^^^^^^^^^^^^^^^^^^TEXT:  Ltd (#12324)^^^^^^^^^^^^^^^^^^^
 *******************************************************************OUTER LOOP 10:******************************************************************** 
(Inside TokenIterator::next()) The next token is:  Co (#3539)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 1
 (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is:  Co (#3539)
            (Inside TokenTree::draft()) Start forwarding in draft model: time 1
            (Inside TokenTree::draft()) Start forwarding in draft model: time 2
            (Inside TokenTree::draft()) Start forwarding in draft model: time 3
            (Inside TokenTree::draft()) Start forwarding in draft model: time 4
            (Inside TokenTree::draft()) Start forwarding in draft model: time 5
            (Inside TokenTree::draft()) Start forwarding in draft model: time 6
            (Inside TokenTree::draft()) Start forwarding in draft model: time 7
            (Inside TokenTree::draft()) n_saved_tokens: 7; n_nodes: 12

===================================DEBUG TOKEN TREE START====================================
[ACC] " Co" 1.00
 [REJ] " Ltd" 0.56
  [REJ] " Co" 0.75
   [REJ] " Ltd" 0.87
    [REJ] " Co" 0.77
     [REJ] " Ltd" 0.91
      [REJ] " Co" 0.80
       [REJ] " Ltd" 0.92
    [REJ] "\n\n" 0.23
   [REJ] " Co" 0.13
  [REJ] " N" 0.25
 [REJ] " Resources" 0.44

===================================DEBUG TOKEN TREE END====================================
     (Inside SpecTokenIterator::decode()) token queue:  ., (#2572), 

^^^^^^^^^^^^^^^^^^^TEXT:  Co (#3539)^^^^^^^^^^^^^^^^^^^
 *******************************************************************OUTER LOOP 11:******************************************************************** 
(Inside TokenIterator::next()) The next token is: ., (#2572)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 1
 (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is: ., (#2572)
            (Inside TokenTree::draft()) Start forwarding in draft model: time 1
            (Inside TokenTree::draft()) Start forwarding in draft model: time 2
            (Inside TokenTree::draft()) Start forwarding in draft model: time 3
            (Inside TokenTree::draft()) Start forwarding in draft model: time 4
            (Inside TokenTree::draft()) Start forwarding in draft model: time 5
            (Inside TokenTree::draft()) Start forwarding in draft model: time 6
            (Inside TokenTree::draft()) n_saved_tokens: 6; n_nodes: 12

===================================DEBUG TOKEN TREE START====================================
[ACC] ".," 1.00
 [REJ] " Ltd" 0.84
  [REJ] "." 0.66
   [REJ] " N" 0.69
    [REJ] "IO" 0.97
     [REJ] "IO" 0.55
      [REJ] " Resources" 0.95
     [REJ] "," 0.45
    [REJ] "io" 0.03
   [REJ] " is" 0.31
  [REJ] ".\n\n" 0.34
 [REJ] " a" 0.16

===================================DEBUG TOKEN TREE END====================================
     (Inside SpecTokenIterator::decode()) token queue:  

 (#271), 

^^^^^^^^^^^^^^^^^^^TEXT: ., (#2572)^^^^^^^^^^^^^^^^^^^
 *******************************************************************OUTER LOOP 12:******************************************************************** 
(Inside TokenIterator::next()) The next token is: 

 (#271)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 1
 (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is: 

 (#271)
            (Inside TokenTree::draft()) Start forwarding in draft model: time 1
            (Inside TokenTree::draft()) Start forwarding in draft model: time 2
            (Inside TokenTree::draft()) Start forwarding in draft model: time 3
            (Inside TokenTree::draft()) Start forwarding in draft model: time 4
            (Inside TokenTree::draft()) Start forwarding in draft model: time 5
            (Inside TokenTree::draft()) n_saved_tokens: 5; n_nodes: 11

===================================DEBUG TOKEN TREE START====================================
[ACC] "\n\n" 1.00
 [REJ] "N" 0.55
  [REJ] "IO" 0.98
   [REJ] " is" 0.55
    [REJ] " a" 0.85
     [REJ] " leading" 0.70
     [REJ] " company" 0.30
    [REJ] " an" 0.15
   [REJ] "IO" 0.45
  [REJ] "io" 0.02
 [REJ] "So" 0.45

===================================DEBUG TOKEN TREE END====================================
     (Inside SpecTokenIterator::decode()) token queue:   Resources (#16209), 

^^^^^^^^^^^^^^^^^^^TEXT: 

 (#271)^^^^^^^^^^^^^^^^^^^
 *******************************************************************OUTER LOOP 13:******************************************************************** 
(Inside TokenIterator::next()) The next token is:  Resources (#16209)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 1
 (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is:  Resources (#16209)
            (Inside TokenTree::draft()) Start forwarding in draft model: time 1
            (Inside TokenTree::draft()) Start forwarding in draft model: time 2
            (Inside TokenTree::draft()) Start forwarding in draft model: time 3
            (Inside TokenTree::draft()) Start forwarding in draft model: time 4
            (Inside TokenTree::draft()) Start forwarding in draft model: time 5
            (Inside TokenTree::draft()) Start forwarding in draft model: time 6
            (Inside TokenTree::draft()) Start forwarding in draft model: time 7
            (Inside TokenTree::draft()) n_saved_tokens: 7; n_nodes: 12

===================================DEBUG TOKEN TREE START====================================
[ACC] " Resources" 1.00
 [REJ] " Co" 0.94
  [REJ] " Resources" 0.65
   [REJ] " Co" 0.90
    [REJ] " Ltd" 0.90
     [REJ] " Co" 0.58
      [REJ] ".," 0.72
       [REJ] " N" 0.55
       [REJ] "\n\n" 0.45
      [REJ] "." 0.28
     [REJ] "," 0.42
  [REJ] " Ltd" 0.35

===================================DEBUG TOKEN TREE END====================================
     (Inside SpecTokenIterator::decode()) token queue:  

 (#271), 

^^^^^^^^^^^^^^^^^^^TEXT:  Resources (#16209)^^^^^^^^^^^^^^^^^^^
 *******************************************************************OUTER LOOP 14:******************************************************************** 
(Inside TokenIterator::next()) The next token is: 

 (#271)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 1
 (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is: 

 (#271)
            (Inside TokenTree::draft()) Start forwarding in draft model: time 1
            (Inside TokenTree::draft()) Start forwarding in draft model: time 2
            (Inside TokenTree::draft()) Start forwarding in draft model: time 3
            (Inside TokenTree::draft()) Start forwarding in draft model: time 4
            (Inside TokenTree::draft()) Start forwarding in draft model: time 5
            (Inside TokenTree::draft()) Start forwarding in draft model: time 6
            (Inside TokenTree::draft()) Start forwarding in draft model: time 7
            (Inside TokenTree::draft()) Start forwarding in draft model: time 8
            (Inside TokenTree::draft()) Start forwarding in draft model: time 9
            (Inside TokenTree::draft()) Start forwarding in draft model: time 10
            (Inside TokenTree::draft()) n_saved_tokens: 10; n_nodes: 12

===================================DEBUG TOKEN TREE START====================================
[ACC] "\n\n" 1.00
 [REJ] " Resources" 0.51
  [REJ] "\n\n" 0.88
   [REJ] " N" 0.75
    [REJ] "IO" 0.92
     [REJ] "\n\n" 0.65
      [REJ] " company" 0.70
 [REJ] " N" 0.49
  [REJ] "IO" 0.99
   [REJ] " is" 0.54
    [REJ] " a" 0.88
     [REJ] " leading" 0.71

===================================DEBUG TOKEN TREE END====================================
     (Inside SpecTokenIterator::decode()) token queue:  N (#45), 

^^^^^^^^^^^^^^^^^^^TEXT: 

 (#271)^^^^^^^^^^^^^^^^^^^
 *******************************************************************OUTER LOOP 15:******************************************************************** 
(Inside TokenIterator::next()) The next token is: N (#45)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 1
 (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is: N (#45)
            (Inside TokenTree::draft()) Start forwarding in draft model: time 1
            (Inside TokenTree::draft()) Start forwarding in draft model: time 2
            (Inside TokenTree::draft()) Start forwarding in draft model: time 3
            (Inside TokenTree::draft()) Start forwarding in draft model: time 4
            (Inside TokenTree::draft()) Start forwarding in draft model: time 5
            (Inside TokenTree::draft()) n_saved_tokens: 5; n_nodes: 11

===================================DEBUG TOKEN TREE START====================================
[ACC] "N" 1.00
 [REJ] "IO" 0.99
  [REJ] " is" 0.53
   [REJ] " a" 0.87
    [REJ] " leading" 0.70
     [REJ] " provider" 0.53
     [REJ] " technology" 0.47
    [REJ] " company" 0.30
   [REJ] " an" 0.13
  [REJ] "IO" 0.47
 [REJ] "io" 0.01

===================================DEBUG TOKEN TREE END====================================
     (Inside SpecTokenIterator::decode()) token queue:   Resources (#16209), 

^^^^^^^^^^^^^^^^^^^TEXT: N (#45)^^^^^^^^^^^^^^^^^^^
 *******************************************************************OUTER LOOP 16:******************************************************************** 
(Inside TokenIterator::next()) The next token is:  Resources (#16209)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 1
 (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is:  Resources (#16209)
            (Inside TokenTree::draft()) Start forwarding in draft model: time 1
            (Inside TokenTree::draft()) Start forwarding in draft model: time 2
            (Inside TokenTree::draft()) Start forwarding in draft model: time 3
            (Inside TokenTree::draft()) Start forwarding in draft model: time 4
            (Inside TokenTree::draft()) Start forwarding in draft model: time 5
            (Inside TokenTree::draft()) Start forwarding in draft model: time 6
            (Inside TokenTree::draft()) Start forwarding in draft model: time 7
            (Inside TokenTree::draft()) Start forwarding in draft model: time 8
            (Inside TokenTree::draft()) Start forwarding in draft model: time 9
            (Inside TokenTree::draft()) n_saved_tokens: 9; n_nodes: 12

===================================DEBUG TOKEN TREE START====================================
[ACC] " Resources" 1.00
 [ACC] "\n\n" 0.51
  [ACC] "N" 0.70
   [REJ] "IO" 0.89
    [REJ] " Resources" 0.72
     [REJ] " Co" 0.75
 [REJ] " Co" 0.49
  [REJ] " Resources" 0.61
   [REJ] " Co" 0.77
    [REJ] " Ltd" 0.90
     [REJ] " Co" 0.67
  [REJ] " Ltd" 0.39

===================================DEBUG TOKEN TREE END====================================
     (Inside SpecTokenIterator::decode()) token queue:  

 (#271),  N (#45),  ., (#2572), 

^^^^^^^^^^^^^^^^^^^TEXT:  Resources (#16209)^^^^^^^^^^^^^^^^^^^

[INFO ] prefill time: 12.543 s
[INFO ] prefill speed (6 tokens): 0.47835446065534565 tokens/s
[INFO ] decode speed (15 tokens): 0.04229200089095148 tokens/s
[INFO ] total speed: 0.0571864277544796 tokens/s
Speculative token tree statistics:
- 13 iterations, 18 generated tokens
- 1.385 tokens/iteration
- 6.769 draft-forwards/iteration
- Accept ratio: 3.650%
- Draft effective ratio: 5.682%

Process finished with exit code 0
```

Beautiful debug:

```
/home/shuojiang/New-Projects/Attempt2/PowerServe/cmake-build-debug/bin/run --work-folder /home/shuojiang/New-Projects/Attempt2/PowerServe/models/ --model smallthinker-3b --draft-model smallthinker-0.5b --thread 4 --prompt "Please introduce the company NIO." --no-qnn
[INFO ] Compiled on: Feb  4 2025 at 11:33:14
[INFO ] Load model qwen2 ...
[INFO ] Load model qwen2 ...
[INFO ] after model init: [Memory(MB)] VMS: 4122, RSS: 4118
[INFO ] after platform init: [Memory(MB)] VMS: 7195, RSS: 4118
[INFO ] after attn init: [Memory(MB)] VMS: 7195, RSS: 4118
[DEBUG] special_bos         : 151643: <|endoftext|>
[DEBUG] special_eos         : 151645: <|im_end|>
[DEBUG] special_pad         : 151643: <|endoftext|>
[DEBUG] special_eot         : 151645: <|im_end|>
[INFO ] after tokenizer init: [Memory(MB)] VMS: 7245, RSS: 4169
[INFO ] seed: 0
[INFO ] after sampler init: [Memory(MB)] VMS: 7245, RSS: 4169
[INFO ] prompt      : "Please introduce the company NIO."
[INFO ] n_predicts  : 16
[INFO ] model arch  : qwen2
[INFO ] n_threads   : 4
[INFO ] batch_size   : 128
Please introduce the company NIO.
Not bug here1......
Not bug here2......
no bug inside 1......
no bug inside 2......
target model id: smallthinker_3b
no bug inside 2.3......
draft model id: smallthinker_500m
no bug inside 2.4......
no bug inside 2.5......
no bug inside 3......
no bug inside 4......
no bug inside 5......
no bug inside 6......
Not bug here3......
Not bug here4......
 *******************************************************************OUTER LOOP 1:******************************************************************** 
(Inside TokenIterator::next()) The next token is: . (#13)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 1
 (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is: . (#13)
            (Inside TokenTree::draft()) Start forwarding in draft model: time 1
            (Inside TokenTree::draft()) Start forwarding in draft model: time 2
            (Inside TokenTree::draft()) Start forwarding in draft model: time 3
            (Inside TokenTree::draft()) Start forwarding in draft model: time 4
            (Inside TokenTree::draft()) Start forwarding in draft model: time 5
            (Inside TokenTree::draft()) Start forwarding in draft model: time 6
            (Inside TokenTree::draft()) Start forwarding in draft model: time 7
            (Inside TokenTree::draft()) Start forwarding in draft model: time 8
            (Inside TokenTree::draft()) n_saved_tokens: 8; n_nodes: 12

===================================DEBUG TOKEN TREE START====================================
[ACC] "." 1.00
├── [ACC] " N" 0.84
│   └── [ACC] "IO" 0.99
│       └── [REJ] " is" 0.88
│           └── [REJ] " a" 0.84
│               ├── [REJ] " leading" 0.73
│               │   ├── [REJ] " provider" 0.54
│               │   │   └── [REJ] " of" 0.98
│               │   │       └── [REJ] " innovative" 0.68
│               │   └── [REJ] " technology" 0.46
│               └── [REJ] " company" 0.27
└── [REJ] " I" 0.16

===================================DEBUG TOKEN TREE END====================================
     (Inside SpecTokenIterator::decode()) token queue:   N (#451),  IO (#3810),  IO (#3810), 
 *******************************************************************OUTER LOOP 2:******************************************************************** 
(Inside TokenIterator::next()) The next token is:  N (#451)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 3

^^^^^^^^^^^^^^^^^^^TEXT:  N (#451)^^^^^^^^^^^^^^^^^^^
 *******************************************************************OUTER LOOP 3:******************************************************************** 
(Inside TokenIterator::next()) The next token is: IO (#3810)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 2

^^^^^^^^^^^^^^^^^^^TEXT: IO (#3810)^^^^^^^^^^^^^^^^^^^
 *******************************************************************OUTER LOOP 4:******************************************************************** 
(Inside TokenIterator::next()) The next token is: IO (#3810)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 1
 (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is: IO (#3810)
            (Inside TokenTree::draft()) Start forwarding in draft model: time 1
            (Inside TokenTree::draft()) Start forwarding in draft model: time 2
            (Inside TokenTree::draft()) Start forwarding in draft model: time 3
            (Inside TokenTree::draft()) Start forwarding in draft model: time 4
            (Inside TokenTree::draft()) n_saved_tokens: 4; n_nodes: 9

===================================DEBUG TOKEN TREE START====================================
[ACC] "IO" 1.00
├── [REJ] " is" 0.75
│   ├── [REJ] " a" 0.75
│   │   ├── [REJ] " leading" 0.54
│   │   │   ├── [REJ] " provider" 0.60
│   │   │   └── [REJ] " technology" 0.40
│   │   └── [REJ] " company" 0.46
│   └── [REJ] " the" 0.25
└── [REJ] "," 0.25

===================================DEBUG TOKEN TREE END====================================
     (Inside SpecTokenIterator::decode()) token queue:   Resources (#16209), 

^^^^^^^^^^^^^^^^^^^TEXT: IO (#3810)^^^^^^^^^^^^^^^^^^^
 *******************************************************************OUTER LOOP 5:******************************************************************** 
(Inside TokenIterator::next()) The next token is:  Resources (#16209)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 1
 (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is:  Resources (#16209)
            (Inside TokenTree::draft()) Start forwarding in draft model: time 1
            (Inside TokenTree::draft()) Start forwarding in draft model: time 2
            (Inside TokenTree::draft()) Start forwarding in draft model: time 3
            (Inside TokenTree::draft()) Start forwarding in draft model: time 4
            (Inside TokenTree::draft()) Start forwarding in draft model: time 5
            (Inside TokenTree::draft()) Start forwarding in draft model: time 6
            (Inside TokenTree::draft()) n_saved_tokens: 6; n_nodes: 12

===================================DEBUG TOKEN TREE START====================================
[ACC] " Resources" 1.00
├── [REJ] " is" 0.72
│   ├── [REJ] " a" 0.80
│   │   ├── [REJ] " leading" 0.67
│   │   │   ├── [REJ] " provider" 0.76
│   │   │   │   └── [REJ] " of" 0.96
│   │   │   │       ├── [REJ] " innovative" 0.67
│   │   │   │       └── [REJ] " high" 0.33
│   │   │   └── [REJ] " global" 0.24
│   │   └── [REJ] " company" 0.33
│   └── [REJ] " the" 0.20
└── [REJ] "," 0.28

===================================DEBUG TOKEN TREE END====================================
     (Inside SpecTokenIterator::decode()) token queue:   Co (#3539), 

^^^^^^^^^^^^^^^^^^^TEXT:  Resources (#16209)^^^^^^^^^^^^^^^^^^^
 *******************************************************************OUTER LOOP 6:******************************************************************** 
(Inside TokenIterator::next()) The next token is:  Co (#3539)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 1
 (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is:  Co (#3539)
            (Inside TokenTree::draft()) Start forwarding in draft model: time 1
            (Inside TokenTree::draft()) Start forwarding in draft model: time 2
            (Inside TokenTree::draft()) Start forwarding in draft model: time 3
            (Inside TokenTree::draft()) Start forwarding in draft model: time 4
            (Inside TokenTree::draft()) Start forwarding in draft model: time 5
            (Inside TokenTree::draft()) n_saved_tokens: 5; n_nodes: 11

===================================DEBUG TOKEN TREE START====================================
[ACC] " Co" 1.00
├── [REJ] "." 0.59
│   ├── [REJ] " Ltd" 0.78
│   │   ├── [REJ] "." 0.71
│   │   │   ├── [REJ] " is" 0.69
│   │   │   │   ├── [REJ] " a" 0.87
│   │   │   │   └── [REJ] " an" 0.13
│   │   │   └── [REJ] " (" 0.31
│   │   └── [REJ] ".," 0.29
│   └── [REJ] " is" 0.22
└── [REJ] ".," 0.41

===================================DEBUG TOKEN TREE END====================================
     (Inside SpecTokenIterator::decode()) token queue:   Resources (#16209), 

^^^^^^^^^^^^^^^^^^^TEXT:  Co (#3539)^^^^^^^^^^^^^^^^^^^
 *******************************************************************OUTER LOOP 7:******************************************************************** 
(Inside TokenIterator::next()) The next token is:  Resources (#16209)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 1
 (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is:  Resources (#16209)
            (Inside TokenTree::draft()) Start forwarding in draft model: time 1
            (Inside TokenTree::draft()) Start forwarding in draft model: time 2
            (Inside TokenTree::draft()) Start forwarding in draft model: time 3
            (Inside TokenTree::draft()) Start forwarding in draft model: time 4
            (Inside TokenTree::draft()) Start forwarding in draft model: time 5
            (Inside TokenTree::draft()) Start forwarding in draft model: time 6
            (Inside TokenTree::draft()) Start forwarding in draft model: time 7
            (Inside TokenTree::draft()) n_saved_tokens: 7; n_nodes: 12

===================================DEBUG TOKEN TREE START====================================
[ACC] " Resources" 1.00
├── [REJ] " is" 0.52
│   └── [REJ] " a" 0.85
│       ├── [REJ] " leading" 0.62
│       │   ├── [REJ] " provider" 0.61
│       │   └── [REJ] " global" 0.39
│       └── [REJ] " company" 0.38
└── [REJ] " Inc" 0.48
    ├── [REJ] "." 0.52
    │   └── [REJ] " N" 0.59
    └── [REJ] " Resources" 0.48
        └── [REJ] " Inc" 0.66

===================================DEBUG TOKEN TREE END====================================
     (Inside SpecTokenIterator::decode()) token queue:   Co (#3539), 

^^^^^^^^^^^^^^^^^^^TEXT:  Resources (#16209)^^^^^^^^^^^^^^^^^^^
 *******************************************************************OUTER LOOP 8:******************************************************************** 
(Inside TokenIterator::next()) The next token is:  Co (#3539)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 1
 (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is:  Co (#3539)
            (Inside TokenTree::draft()) Start forwarding in draft model: time 1
            (Inside TokenTree::draft()) Start forwarding in draft model: time 2
            (Inside TokenTree::draft()) Start forwarding in draft model: time 3
            (Inside TokenTree::draft()) Start forwarding in draft model: time 4
            (Inside TokenTree::draft()) Start forwarding in draft model: time 5
            (Inside TokenTree::draft()) Start forwarding in draft model: time 6
            (Inside TokenTree::draft()) Start forwarding in draft model: time 7
            (Inside TokenTree::draft()) Start forwarding in draft model: time 8
            (Inside TokenTree::draft()) Start forwarding in draft model: time 9
            (Inside TokenTree::draft()) n_saved_tokens: 9; n_nodes: 12

===================================DEBUG TOKEN TREE START====================================
[ACC] " Co" 1.00
├── [REJ] " Resources" 0.72
│   └── [REJ] " Co" 0.86
│       ├── [REJ] " Resources" 0.71
│       │   └── [REJ] " Co" 0.94
│       │       └── [REJ] " Resources" 0.73
│       │           └── [REJ] " Co" 0.95
│       │               └── [REJ] " Resources" 0.79
│       │                   └── [REJ] " Co" 0.95
│       │                       └── [REJ] " Resources" 0.86
│       └── [REJ] "\n\n" 0.29
└── [ACC] " Ltd" 0.28

===================================DEBUG TOKEN TREE END====================================
     (Inside SpecTokenIterator::decode()) token queue:   Ltd (#12324),   Co (#3539), 

^^^^^^^^^^^^^^^^^^^TEXT:  Co (#3539)^^^^^^^^^^^^^^^^^^^
 *******************************************************************OUTER LOOP 9:******************************************************************** 
(Inside TokenIterator::next()) The next token is:  Ltd (#12324)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 2

^^^^^^^^^^^^^^^^^^^TEXT:  Ltd (#12324)^^^^^^^^^^^^^^^^^^^
 *******************************************************************OUTER LOOP 10:******************************************************************** 
(Inside TokenIterator::next()) The next token is:  Co (#3539)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 1
 (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is:  Co (#3539)
            (Inside TokenTree::draft()) Start forwarding in draft model: time 1
            (Inside TokenTree::draft()) Start forwarding in draft model: time 2
            (Inside TokenTree::draft()) Start forwarding in draft model: time 3
            (Inside TokenTree::draft()) Start forwarding in draft model: time 4
            (Inside TokenTree::draft()) Start forwarding in draft model: time 5
            (Inside TokenTree::draft()) Start forwarding in draft model: time 6
            (Inside TokenTree::draft()) Start forwarding in draft model: time 7
            (Inside TokenTree::draft()) n_saved_tokens: 7; n_nodes: 12

===================================DEBUG TOKEN TREE START====================================
[ACC] " Co" 1.00
├── [REJ] " Ltd" 0.56
│   ├── [REJ] " Co" 0.75
│   │   ├── [REJ] " Ltd" 0.87
│   │   │   ├── [REJ] " Co" 0.77
│   │   │   │   └── [REJ] " Ltd" 0.91
│   │   │   │       └── [REJ] " Co" 0.80
│   │   │   │           └── [REJ] " Ltd" 0.92
│   │   │   └── [REJ] "\n\n" 0.23
│   │   └── [REJ] " Co" 0.13
│   └── [REJ] " N" 0.25
└── [REJ] " Resources" 0.44

===================================DEBUG TOKEN TREE END====================================
     (Inside SpecTokenIterator::decode()) token queue:  ., (#2572), 

^^^^^^^^^^^^^^^^^^^TEXT:  Co (#3539)^^^^^^^^^^^^^^^^^^^
 *******************************************************************OUTER LOOP 11:******************************************************************** 
(Inside TokenIterator::next()) The next token is: ., (#2572)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 1
 (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is: ., (#2572)
            (Inside TokenTree::draft()) Start forwarding in draft model: time 1
            (Inside TokenTree::draft()) Start forwarding in draft model: time 2
            (Inside TokenTree::draft()) Start forwarding in draft model: time 3
            (Inside TokenTree::draft()) Start forwarding in draft model: time 4
            (Inside TokenTree::draft()) Start forwarding in draft model: time 5
            (Inside TokenTree::draft()) Start forwarding in draft model: time 6
            (Inside TokenTree::draft()) n_saved_tokens: 6; n_nodes: 12

===================================DEBUG TOKEN TREE START====================================
[ACC] ".," 1.00
├── [REJ] " Ltd" 0.84
│   ├── [REJ] "." 0.66
│   │   ├── [REJ] " N" 0.69
│   │   │   ├── [REJ] "IO" 0.97
│   │   │   │   ├── [REJ] "IO" 0.55
│   │   │   │   │   └── [REJ] " Resources" 0.95
│   │   │   │   └── [REJ] "," 0.45
│   │   │   └── [REJ] "io" 0.03
│   │   └── [REJ] " is" 0.31
│   └── [REJ] ".\n\n" 0.34
└── [REJ] " a" 0.16

===================================DEBUG TOKEN TREE END====================================
     (Inside SpecTokenIterator::decode()) token queue:  

 (#271), 

^^^^^^^^^^^^^^^^^^^TEXT: ., (#2572)^^^^^^^^^^^^^^^^^^^
 *******************************************************************OUTER LOOP 12:******************************************************************** 
(Inside TokenIterator::next()) The next token is: 

 (#271)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 1
 (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is: 

 (#271)
            (Inside TokenTree::draft()) Start forwarding in draft model: time 1
            (Inside TokenTree::draft()) Start forwarding in draft model: time 2
            (Inside TokenTree::draft()) Start forwarding in draft model: time 3
            (Inside TokenTree::draft()) Start forwarding in draft model: time 4
            (Inside TokenTree::draft()) Start forwarding in draft model: time 5
            (Inside TokenTree::draft()) n_saved_tokens: 5; n_nodes: 11

===================================DEBUG TOKEN TREE START====================================
[ACC] "\n\n" 1.00
├── [REJ] "N" 0.55
│   ├── [REJ] "IO" 0.98
│   │   ├── [REJ] " is" 0.55
│   │   │   ├── [REJ] " a" 0.85
│   │   │   │   ├── [REJ] " leading" 0.70
│   │   │   │   └── [REJ] " company" 0.30
│   │   │   └── [REJ] " an" 0.15
│   │   └── [REJ] "IO" 0.45
│   └── [REJ] "io" 0.02
└── [REJ] "So" 0.45

===================================DEBUG TOKEN TREE END====================================
     (Inside SpecTokenIterator::decode()) token queue:   Resources (#16209), 

^^^^^^^^^^^^^^^^^^^TEXT: 

 (#271)^^^^^^^^^^^^^^^^^^^
 *******************************************************************OUTER LOOP 13:******************************************************************** 
(Inside TokenIterator::next()) The next token is:  Resources (#16209)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 1
 (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is:  Resources (#16209)
            (Inside TokenTree::draft()) Start forwarding in draft model: time 1
            (Inside TokenTree::draft()) Start forwarding in draft model: time 2
            (Inside TokenTree::draft()) Start forwarding in draft model: time 3
            (Inside TokenTree::draft()) Start forwarding in draft model: time 4
            (Inside TokenTree::draft()) Start forwarding in draft model: time 5
            (Inside TokenTree::draft()) Start forwarding in draft model: time 6
            (Inside TokenTree::draft()) Start forwarding in draft model: time 7
            (Inside TokenTree::draft()) n_saved_tokens: 7; n_nodes: 12

===================================DEBUG TOKEN TREE START====================================
[ACC] " Resources" 1.00
└── [REJ] " Co" 0.94
    ├── [REJ] " Resources" 0.65
    │   └── [REJ] " Co" 0.90
    │       └── [REJ] " Ltd" 0.90
    │           ├── [REJ] " Co" 0.58
    │           │   ├── [REJ] ".," 0.72
    │           │   │   ├── [REJ] " N" 0.55
    │           │   │   └── [REJ] "\n\n" 0.45
    │           │   └── [REJ] "." 0.28
    │           └── [REJ] "," 0.42
    └── [REJ] " Ltd" 0.35

===================================DEBUG TOKEN TREE END====================================
     (Inside SpecTokenIterator::decode()) token queue:  

 (#271), 

^^^^^^^^^^^^^^^^^^^TEXT:  Resources (#16209)^^^^^^^^^^^^^^^^^^^
 *******************************************************************OUTER LOOP 14:******************************************************************** 
(Inside TokenIterator::next()) The next token is: 

 (#271)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 1
 (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is: 

 (#271)
            (Inside TokenTree::draft()) Start forwarding in draft model: time 1
            (Inside TokenTree::draft()) Start forwarding in draft model: time 2
            (Inside TokenTree::draft()) Start forwarding in draft model: time 3
            (Inside TokenTree::draft()) Start forwarding in draft model: time 4
            (Inside TokenTree::draft()) Start forwarding in draft model: time 5
            (Inside TokenTree::draft()) Start forwarding in draft model: time 6
            (Inside TokenTree::draft()) Start forwarding in draft model: time 7
            (Inside TokenTree::draft()) Start forwarding in draft model: time 8
            (Inside TokenTree::draft()) Start forwarding in draft model: time 9
            (Inside TokenTree::draft()) Start forwarding in draft model: time 10
            (Inside TokenTree::draft()) n_saved_tokens: 10; n_nodes: 12

===================================DEBUG TOKEN TREE START====================================
[ACC] "\n\n" 1.00
├── [REJ] " Resources" 0.51
│   └── [REJ] "\n\n" 0.88
│       └── [REJ] " N" 0.75
│           └── [REJ] "IO" 0.92
│               └── [REJ] "\n\n" 0.65
│                   └── [REJ] " company" 0.70
└── [REJ] " N" 0.49
    └── [REJ] "IO" 0.99
        └── [REJ] " is" 0.54
            └── [REJ] " a" 0.88
                └── [REJ] " leading" 0.71

===================================DEBUG TOKEN TREE END====================================
     (Inside SpecTokenIterator::decode()) token queue:  N (#45), 

^^^^^^^^^^^^^^^^^^^TEXT: 

 (#271)^^^^^^^^^^^^^^^^^^^
 *******************************************************************OUTER LOOP 15:******************************************************************** 
(Inside TokenIterator::next()) The next token is: N (#45)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 1
 (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is: N (#45)
            (Inside TokenTree::draft()) Start forwarding in draft model: time 1
            (Inside TokenTree::draft()) Start forwarding in draft model: time 2
            (Inside TokenTree::draft()) Start forwarding in draft model: time 3
            (Inside TokenTree::draft()) Start forwarding in draft model: time 4
            (Inside TokenTree::draft()) Start forwarding in draft model: time 5
            (Inside TokenTree::draft()) n_saved_tokens: 5; n_nodes: 11

===================================DEBUG TOKEN TREE START====================================
[ACC] "N" 1.00
├── [REJ] "IO" 0.99
│   ├── [REJ] " is" 0.53
│   │   ├── [REJ] " a" 0.87
│   │   │   ├── [REJ] " leading" 0.70
│   │   │   │   ├── [REJ] " provider" 0.53
│   │   │   │   └── [REJ] " technology" 0.47
│   │   │   └── [REJ] " company" 0.30
│   │   └── [REJ] " an" 0.13
│   └── [REJ] "IO" 0.47
└── [REJ] "io" 0.01

===================================DEBUG TOKEN TREE END====================================
     (Inside SpecTokenIterator::decode()) token queue:   Resources (#16209), 

^^^^^^^^^^^^^^^^^^^TEXT: N (#45)^^^^^^^^^^^^^^^^^^^
 *******************************************************************OUTER LOOP 16:******************************************************************** 
(Inside TokenIterator::next()) The next token is:  Resources (#16209)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 1
 (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is:  Resources (#16209)
            (Inside TokenTree::draft()) Start forwarding in draft model: time 1
            (Inside TokenTree::draft()) Start forwarding in draft model: time 2
            (Inside TokenTree::draft()) Start forwarding in draft model: time 3
            (Inside TokenTree::draft()) Start forwarding in draft model: time 4
            (Inside TokenTree::draft()) Start forwarding in draft model: time 5
            (Inside TokenTree::draft()) Start forwarding in draft model: time 6
            (Inside TokenTree::draft()) Start forwarding in draft model: time 7
            (Inside TokenTree::draft()) Start forwarding in draft model: time 8
            (Inside TokenTree::draft()) Start forwarding in draft model: time 9
            (Inside TokenTree::draft()) n_saved_tokens: 9; n_nodes: 12

===================================DEBUG TOKEN TREE START====================================
[ACC] " Resources" 1.00
├── [ACC] "\n\n" 0.51
│   └── [ACC] "N" 0.70
│       └── [REJ] "IO" 0.89
│           └── [REJ] " Resources" 0.72
│               └── [REJ] " Co" 0.75
└── [REJ] " Co" 0.49
    ├── [REJ] " Resources" 0.61
    │   └── [REJ] " Co" 0.77
    │       └── [REJ] " Ltd" 0.90
    │           └── [REJ] " Co" 0.67
    └── [REJ] " Ltd" 0.39

===================================DEBUG TOKEN TREE END====================================
     (Inside SpecTokenIterator::decode()) token queue:  

 (#271),  N (#45),  ., (#2572), 

^^^^^^^^^^^^^^^^^^^TEXT:  Resources (#16209)^^^^^^^^^^^^^^^^^^^

[INFO ] prefill time: 12.869 s
[INFO ] prefill speed (6 tokens): 0.46623669282772556 tokens/s
[INFO ] decode speed (15 tokens): 0.0429618470157269 tokens/s
[INFO ] total speed: 0.05800848581278176 tokens/s
Speculative token tree statistics:
- 13 iterations, 18 generated tokens
- 1.385 tokens/iteration
- 6.769 draft-forwards/iteration
- Accept ratio: 3.650%
- Draft effective ratio: 5.682%

Process finished with exit code 0
```

Debug (top_k = 2, batch = 12):

```
/home/shuojiang/New-Projects/Attempt2/PowerServe/cmake-build-debug/bin/run --work-folder /home/shuojiang/New-Projects/Attempt2/PowerServe/models/ --model smallthinker-3b --draft-model smallthinker-0.5b --thread 4 --prompt "Please introduce the company NIO." --no-qnn
[INFO ] Compiled on: Feb  4 2025 at 11:33:14
[INFO ] Load model qwen2 ...
[INFO ] Load model qwen2 ...
[INFO ] after model init: [Memory(MB)] VMS: 4122, RSS: 4117
[INFO ] after platform init: [Memory(MB)] VMS: 7195, RSS: 4118
[INFO ] after attn init: [Memory(MB)] VMS: 7195, RSS: 4118
[DEBUG] special_bos         : 151643: <|endoftext|>
[DEBUG] special_eos         : 151645: <|im_end|>
[DEBUG] special_pad         : 151643: <|endoftext|>
[DEBUG] special_eot         : 151645: <|im_end|>
[INFO ] after tokenizer init: [Memory(MB)] VMS: 7245, RSS: 4169
[INFO ] seed: 0
[INFO ] after sampler init: [Memory(MB)] VMS: 7245, RSS: 4169
[INFO ] prompt      : "Please introduce the company NIO."
[INFO ] n_predicts  : 16
[INFO ] model arch  : qwen2
[INFO ] n_threads   : 4
[INFO ] batch_size   : 128
Please introduce the company NIO.
Not bug here1......
Not bug here2......
no bug inside 1......
no bug inside 2......
target model id: smallthinker_3b
no bug inside 2.3......
draft model id: smallthinker_500m
no bug inside 2.4......
no bug inside 2.5......
no bug inside 3......
no bug inside 4......
no bug inside 5......
no bug inside 6......
Not bug here3......
Not bug here4......
 *******************************************************************OUTER LOOP 1:******************************************************************** 
(Inside TokenIterator::next()) The next token is: . (#13)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 1
 (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is: . (#13)
            (Inside TokenTree::draft()) Start forwarding in draft model: time 1
            (Inside TokenTree::draft()) Start forwarding in draft model: time 2
            (Inside TokenTree::draft()) Start forwarding in draft model: time 3
            (Inside TokenTree::draft()) Start forwarding in draft model: time 4
            (Inside TokenTree::draft()) Start forwarding in draft model: time 5
            (Inside TokenTree::draft()) Start forwarding in draft model: time 6
            (Inside TokenTree::draft()) Start forwarding in draft model: time 7
            (Inside TokenTree::draft()) Start forwarding in draft model: time 8
            (Inside TokenTree::draft()) n_saved_tokens: 8; n_nodes: 12
      (Inside TokenTree::generate_tokens()) Start forwarding in target model (slow!)
            (Inside TokenTree::verify()) n_generate_tokens: 3; stat.n_generated_tokens: 3 
            (Inside TokenTree::verify()) n_accepted_tokens: 2; stat.n_accepted_tokens: 2 

===================================DEBUG TOKEN TREE START====================================
[ACC] "." 1.00
├── [ACC] " N" 0.84
│   └── [ACC] "IO" 0.99
│       └── [REJ] " is" 0.88
│           └── [REJ] " a" 0.84
│               ├── [REJ] " leading" 0.73
│               │   ├── [REJ] " provider" 0.54
│               │   │   └── [REJ] " of" 0.98
│               │   │       └── [REJ] " innovative" 0.68
│               │   └── [REJ] " technology" 0.46
│               └── [REJ] " company" 0.27
└── [REJ] " I" 0.16

===================================DEBUG TOKEN TREE END====================================
     (Inside SpecTokenIterator::decode()) token queue:   N (#451),  IO (#3810),  IO (#3810), 
 *******************************************************************OUTER LOOP 2:******************************************************************** 
(Inside TokenIterator::next()) The next token is:  N (#451)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 3

^^^^^^^^^^^^^^^^^^^TEXT:  N (#451)^^^^^^^^^^^^^^^^^^^
 *******************************************************************OUTER LOOP 3:******************************************************************** 
(Inside TokenIterator::next()) The next token is: IO (#3810)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 2

^^^^^^^^^^^^^^^^^^^TEXT: IO (#3810)^^^^^^^^^^^^^^^^^^^
 *******************************************************************OUTER LOOP 4:******************************************************************** 
(Inside TokenIterator::next()) The next token is: IO (#3810)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 1
 (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is: IO (#3810)
            (Inside TokenTree::draft()) Start forwarding in draft model: time 1
            (Inside TokenTree::draft()) Start forwarding in draft model: time 2
            (Inside TokenTree::draft()) Start forwarding in draft model: time 3
            (Inside TokenTree::draft()) Start forwarding in draft model: time 4
            (Inside TokenTree::draft()) n_saved_tokens: 4; n_nodes: 9
      (Inside TokenTree::generate_tokens()) Start forwarding in target model (slow!)
            (Inside TokenTree::verify()) n_generate_tokens: 1; stat.n_generated_tokens: 4 
            (Inside TokenTree::verify()) n_accepted_tokens: 0; stat.n_accepted_tokens: 2 

===================================DEBUG TOKEN TREE START====================================
[ACC] "IO" 1.00
├── [REJ] " is" 0.75
│   ├── [REJ] " a" 0.75
│   │   ├── [REJ] " leading" 0.54
│   │   │   ├── [REJ] " provider" 0.60
│   │   │   └── [REJ] " technology" 0.40
│   │   └── [REJ] " company" 0.46
│   └── [REJ] " the" 0.25
└── [REJ] "," 0.25

===================================DEBUG TOKEN TREE END====================================
     (Inside SpecTokenIterator::decode()) token queue:   Resources (#16209), 

^^^^^^^^^^^^^^^^^^^TEXT: IO (#3810)^^^^^^^^^^^^^^^^^^^
 *******************************************************************OUTER LOOP 5:******************************************************************** 
(Inside TokenIterator::next()) The next token is:  Resources (#16209)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 1
 (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is:  Resources (#16209)
            (Inside TokenTree::draft()) Start forwarding in draft model: time 1
            (Inside TokenTree::draft()) Start forwarding in draft model: time 2
            (Inside TokenTree::draft()) Start forwarding in draft model: time 3
            (Inside TokenTree::draft()) Start forwarding in draft model: time 4
            (Inside TokenTree::draft()) Start forwarding in draft model: time 5
            (Inside TokenTree::draft()) Start forwarding in draft model: time 6
            (Inside TokenTree::draft()) n_saved_tokens: 6; n_nodes: 12
      (Inside TokenTree::generate_tokens()) Start forwarding in target model (slow!)
            (Inside TokenTree::verify()) n_generate_tokens: 1; stat.n_generated_tokens: 5 
            (Inside TokenTree::verify()) n_accepted_tokens: 0; stat.n_accepted_tokens: 2 

===================================DEBUG TOKEN TREE START====================================
[ACC] " Resources" 1.00
├── [REJ] " is" 0.72
│   ├── [REJ] " a" 0.80
│   │   ├── [REJ] " leading" 0.67
│   │   │   ├── [REJ] " provider" 0.76
│   │   │   │   └── [REJ] " of" 0.96
│   │   │   │       ├── [REJ] " innovative" 0.67
│   │   │   │       └── [REJ] " high" 0.33
│   │   │   └── [REJ] " global" 0.24
│   │   └── [REJ] " company" 0.33
│   └── [REJ] " the" 0.20
└── [REJ] "," 0.28

===================================DEBUG TOKEN TREE END====================================
     (Inside SpecTokenIterator::decode()) token queue:   Co (#3539), 

^^^^^^^^^^^^^^^^^^^TEXT:  Resources (#16209)^^^^^^^^^^^^^^^^^^^
 *******************************************************************OUTER LOOP 6:******************************************************************** 
(Inside TokenIterator::next()) The next token is:  Co (#3539)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 1
 (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is:  Co (#3539)
            (Inside TokenTree::draft()) Start forwarding in draft model: time 1
            (Inside TokenTree::draft()) Start forwarding in draft model: time 2
            (Inside TokenTree::draft()) Start forwarding in draft model: time 3
            (Inside TokenTree::draft()) Start forwarding in draft model: time 4
            (Inside TokenTree::draft()) Start forwarding in draft model: time 5
            (Inside TokenTree::draft()) n_saved_tokens: 5; n_nodes: 11
      (Inside TokenTree::generate_tokens()) Start forwarding in target model (slow!)
            (Inside TokenTree::verify()) n_generate_tokens: 1; stat.n_generated_tokens: 6 
            (Inside TokenTree::verify()) n_accepted_tokens: 0; stat.n_accepted_tokens: 2 

===================================DEBUG TOKEN TREE START====================================
[ACC] " Co" 1.00
├── [REJ] "." 0.59
│   ├── [REJ] " Ltd" 0.78
│   │   ├── [REJ] "." 0.71
│   │   │   ├── [REJ] " is" 0.69
│   │   │   │   ├── [REJ] " a" 0.87
│   │   │   │   └── [REJ] " an" 0.13
│   │   │   └── [REJ] " (" 0.31
│   │   └── [REJ] ".," 0.29
│   └── [REJ] " is" 0.22
└── [REJ] ".," 0.41

===================================DEBUG TOKEN TREE END====================================
     (Inside SpecTokenIterator::decode()) token queue:   Resources (#16209), 

^^^^^^^^^^^^^^^^^^^TEXT:  Co (#3539)^^^^^^^^^^^^^^^^^^^
 *******************************************************************OUTER LOOP 7:******************************************************************** 
(Inside TokenIterator::next()) The next token is:  Resources (#16209)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 1
 (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is:  Resources (#16209)
            (Inside TokenTree::draft()) Start forwarding in draft model: time 1
            (Inside TokenTree::draft()) Start forwarding in draft model: time 2
            (Inside TokenTree::draft()) Start forwarding in draft model: time 3
            (Inside TokenTree::draft()) Start forwarding in draft model: time 4
            (Inside TokenTree::draft()) Start forwarding in draft model: time 5
            (Inside TokenTree::draft()) Start forwarding in draft model: time 6
            (Inside TokenTree::draft()) Start forwarding in draft model: time 7
            (Inside TokenTree::draft()) n_saved_tokens: 7; n_nodes: 12
      (Inside TokenTree::generate_tokens()) Start forwarding in target model (slow!)
            (Inside TokenTree::verify()) n_generate_tokens: 1; stat.n_generated_tokens: 7 
            (Inside TokenTree::verify()) n_accepted_tokens: 0; stat.n_accepted_tokens: 2 

===================================DEBUG TOKEN TREE START====================================
[ACC] " Resources" 1.00
├── [REJ] " is" 0.52
│   └── [REJ] " a" 0.85
│       ├── [REJ] " leading" 0.62
│       │   ├── [REJ] " provider" 0.61
│       │   └── [REJ] " global" 0.39
│       └── [REJ] " company" 0.38
└── [REJ] " Inc" 0.48
    ├── [REJ] "." 0.52
    │   └── [REJ] " N" 0.59
    └── [REJ] " Resources" 0.48
        └── [REJ] " Inc" 0.66

===================================DEBUG TOKEN TREE END====================================
     (Inside SpecTokenIterator::decode()) token queue:   Co (#3539), 

^^^^^^^^^^^^^^^^^^^TEXT:  Resources (#16209)^^^^^^^^^^^^^^^^^^^
 *******************************************************************OUTER LOOP 8:******************************************************************** 
(Inside TokenIterator::next()) The next token is:  Co (#3539)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 1
 (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is:  Co (#3539)
            (Inside TokenTree::draft()) Start forwarding in draft model: time 1
            (Inside TokenTree::draft()) Start forwarding in draft model: time 2
            (Inside TokenTree::draft()) Start forwarding in draft model: time 3
            (Inside TokenTree::draft()) Start forwarding in draft model: time 4
            (Inside TokenTree::draft()) Start forwarding in draft model: time 5
            (Inside TokenTree::draft()) Start forwarding in draft model: time 6
            (Inside TokenTree::draft()) Start forwarding in draft model: time 7
            (Inside TokenTree::draft()) Start forwarding in draft model: time 8
            (Inside TokenTree::draft()) Start forwarding in draft model: time 9
            (Inside TokenTree::draft()) n_saved_tokens: 9; n_nodes: 12
      (Inside TokenTree::generate_tokens()) Start forwarding in target model (slow!)
            (Inside TokenTree::verify()) n_generate_tokens: 2; stat.n_generated_tokens: 9 
            (Inside TokenTree::verify()) n_accepted_tokens: 1; stat.n_accepted_tokens: 3 

===================================DEBUG TOKEN TREE START====================================
[ACC] " Co" 1.00
├── [REJ] " Resources" 0.72
│   └── [REJ] " Co" 0.86
│       ├── [REJ] " Resources" 0.71
│       │   └── [REJ] " Co" 0.94
│       │       └── [REJ] " Resources" 0.73
│       │           └── [REJ] " Co" 0.95
│       │               └── [REJ] " Resources" 0.79
│       │                   └── [REJ] " Co" 0.95
│       │                       └── [REJ] " Resources" 0.86
│       └── [REJ] "\n\n" 0.29
└── [ACC] " Ltd" 0.28

===================================DEBUG TOKEN TREE END====================================
     (Inside SpecTokenIterator::decode()) token queue:   Ltd (#12324),   Co (#3539), 

^^^^^^^^^^^^^^^^^^^TEXT:  Co (#3539)^^^^^^^^^^^^^^^^^^^
 *******************************************************************OUTER LOOP 9:******************************************************************** 
(Inside TokenIterator::next()) The next token is:  Ltd (#12324)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 2

^^^^^^^^^^^^^^^^^^^TEXT:  Ltd (#12324)^^^^^^^^^^^^^^^^^^^
 *******************************************************************OUTER LOOP 10:******************************************************************** 
(Inside TokenIterator::next()) The next token is:  Co (#3539)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 1
 (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is:  Co (#3539)
            (Inside TokenTree::draft()) Start forwarding in draft model: time 1
            (Inside TokenTree::draft()) Start forwarding in draft model: time 2
            (Inside TokenTree::draft()) Start forwarding in draft model: time 3
            (Inside TokenTree::draft()) Start forwarding in draft model: time 4
            (Inside TokenTree::draft()) Start forwarding in draft model: time 5
            (Inside TokenTree::draft()) Start forwarding in draft model: time 6
            (Inside TokenTree::draft()) Start forwarding in draft model: time 7
            (Inside TokenTree::draft()) n_saved_tokens: 7; n_nodes: 12
      (Inside TokenTree::generate_tokens()) Start forwarding in target model (slow!)
            (Inside TokenTree::verify()) n_generate_tokens: 1; stat.n_generated_tokens: 10 
            (Inside TokenTree::verify()) n_accepted_tokens: 0; stat.n_accepted_tokens: 3 

===================================DEBUG TOKEN TREE START====================================
[ACC] " Co" 1.00
├── [REJ] " Ltd" 0.56
│   ├── [REJ] " Co" 0.75
│   │   ├── [REJ] " Ltd" 0.87
│   │   │   ├── [REJ] " Co" 0.77
│   │   │   │   └── [REJ] " Ltd" 0.91
│   │   │   │       └── [REJ] " Co" 0.80
│   │   │   │           └── [REJ] " Ltd" 0.92
│   │   │   └── [REJ] "\n\n" 0.23
│   │   └── [REJ] " Co" 0.13
│   └── [REJ] " N" 0.25
└── [REJ] " Resources" 0.44

===================================DEBUG TOKEN TREE END====================================
     (Inside SpecTokenIterator::decode()) token queue:  ., (#2572), 

^^^^^^^^^^^^^^^^^^^TEXT:  Co (#3539)^^^^^^^^^^^^^^^^^^^
 *******************************************************************OUTER LOOP 11:******************************************************************** 
(Inside TokenIterator::next()) The next token is: ., (#2572)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 1
 (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is: ., (#2572)
            (Inside TokenTree::draft()) Start forwarding in draft model: time 1
            (Inside TokenTree::draft()) Start forwarding in draft model: time 2
            (Inside TokenTree::draft()) Start forwarding in draft model: time 3
            (Inside TokenTree::draft()) Start forwarding in draft model: time 4
            (Inside TokenTree::draft()) Start forwarding in draft model: time 5
            (Inside TokenTree::draft()) Start forwarding in draft model: time 6
            (Inside TokenTree::draft()) n_saved_tokens: 6; n_nodes: 12
      (Inside TokenTree::generate_tokens()) Start forwarding in target model (slow!)
            (Inside TokenTree::verify()) n_generate_tokens: 1; stat.n_generated_tokens: 11 
            (Inside TokenTree::verify()) n_accepted_tokens: 0; stat.n_accepted_tokens: 3 

===================================DEBUG TOKEN TREE START====================================
[ACC] ".," 1.00
├── [REJ] " Ltd" 0.84
│   ├── [REJ] "." 0.66
│   │   ├── [REJ] " N" 0.69
│   │   │   ├── [REJ] "IO" 0.97
│   │   │   │   ├── [REJ] "IO" 0.55
│   │   │   │   │   └── [REJ] " Resources" 0.95
│   │   │   │   └── [REJ] "," 0.45
│   │   │   └── [REJ] "io" 0.03
│   │   └── [REJ] " is" 0.31
│   └── [REJ] ".\n\n" 0.34
└── [REJ] " a" 0.16

===================================DEBUG TOKEN TREE END====================================
     (Inside SpecTokenIterator::decode()) token queue:  

 (#271), 

^^^^^^^^^^^^^^^^^^^TEXT: ., (#2572)^^^^^^^^^^^^^^^^^^^
 *******************************************************************OUTER LOOP 12:******************************************************************** 
(Inside TokenIterator::next()) The next token is: 

 (#271)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 1
 (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is: 

 (#271)
            (Inside TokenTree::draft()) Start forwarding in draft model: time 1
            (Inside TokenTree::draft()) Start forwarding in draft model: time 2
            (Inside TokenTree::draft()) Start forwarding in draft model: time 3
            (Inside TokenTree::draft()) Start forwarding in draft model: time 4
            (Inside TokenTree::draft()) Start forwarding in draft model: time 5
            (Inside TokenTree::draft()) n_saved_tokens: 5; n_nodes: 11
      (Inside TokenTree::generate_tokens()) Start forwarding in target model (slow!)
            (Inside TokenTree::verify()) n_generate_tokens: 1; stat.n_generated_tokens: 12 
            (Inside TokenTree::verify()) n_accepted_tokens: 0; stat.n_accepted_tokens: 3 

===================================DEBUG TOKEN TREE START====================================
[ACC] "\n\n" 1.00
├── [REJ] "N" 0.55
│   ├── [REJ] "IO" 0.98
│   │   ├── [REJ] " is" 0.55
│   │   │   ├── [REJ] " a" 0.85
│   │   │   │   ├── [REJ] " leading" 0.70
│   │   │   │   └── [REJ] " company" 0.30
│   │   │   └── [REJ] " an" 0.15
│   │   └── [REJ] "IO" 0.45
│   └── [REJ] "io" 0.02
└── [REJ] "So" 0.45

===================================DEBUG TOKEN TREE END====================================
     (Inside SpecTokenIterator::decode()) token queue:   Resources (#16209), 

^^^^^^^^^^^^^^^^^^^TEXT: 

 (#271)^^^^^^^^^^^^^^^^^^^
 *******************************************************************OUTER LOOP 13:******************************************************************** 
(Inside TokenIterator::next()) The next token is:  Resources (#16209)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 1
 (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is:  Resources (#16209)
            (Inside TokenTree::draft()) Start forwarding in draft model: time 1
            (Inside TokenTree::draft()) Start forwarding in draft model: time 2
            (Inside TokenTree::draft()) Start forwarding in draft model: time 3
            (Inside TokenTree::draft()) Start forwarding in draft model: time 4
            (Inside TokenTree::draft()) Start forwarding in draft model: time 5
            (Inside TokenTree::draft()) Start forwarding in draft model: time 6
            (Inside TokenTree::draft()) Start forwarding in draft model: time 7
            (Inside TokenTree::draft()) n_saved_tokens: 7; n_nodes: 12
      (Inside TokenTree::generate_tokens()) Start forwarding in target model (slow!)
            (Inside TokenTree::verify()) n_generate_tokens: 1; stat.n_generated_tokens: 13 
            (Inside TokenTree::verify()) n_accepted_tokens: 0; stat.n_accepted_tokens: 3 

===================================DEBUG TOKEN TREE START====================================
[ACC] " Resources" 1.00
└── [REJ] " Co" 0.94
    ├── [REJ] " Resources" 0.65
    │   └── [REJ] " Co" 0.90
    │       └── [REJ] " Ltd" 0.90
    │           ├── [REJ] " Co" 0.58
    │           │   ├── [REJ] ".," 0.72
    │           │   │   ├── [REJ] " N" 0.55
    │           │   │   └── [REJ] "\n\n" 0.45
    │           │   └── [REJ] "." 0.28
    │           └── [REJ] "," 0.42
    └── [REJ] " Ltd" 0.35

===================================DEBUG TOKEN TREE END====================================
     (Inside SpecTokenIterator::decode()) token queue:  

 (#271), 

^^^^^^^^^^^^^^^^^^^TEXT:  Resources (#16209)^^^^^^^^^^^^^^^^^^^
 *******************************************************************OUTER LOOP 14:******************************************************************** 
(Inside TokenIterator::next()) The next token is: 

 (#271)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 1
 (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is: 

 (#271)
            (Inside TokenTree::draft()) Start forwarding in draft model: time 1
            (Inside TokenTree::draft()) Start forwarding in draft model: time 2
            (Inside TokenTree::draft()) Start forwarding in draft model: time 3
            (Inside TokenTree::draft()) Start forwarding in draft model: time 4
            (Inside TokenTree::draft()) Start forwarding in draft model: time 5
            (Inside TokenTree::draft()) Start forwarding in draft model: time 6
            (Inside TokenTree::draft()) Start forwarding in draft model: time 7
            (Inside TokenTree::draft()) Start forwarding in draft model: time 8
            (Inside TokenTree::draft()) Start forwarding in draft model: time 9
            (Inside TokenTree::draft()) Start forwarding in draft model: time 10
            (Inside TokenTree::draft()) n_saved_tokens: 10; n_nodes: 12
      (Inside TokenTree::generate_tokens()) Start forwarding in target model (slow!)
            (Inside TokenTree::verify()) n_generate_tokens: 1; stat.n_generated_tokens: 14 
            (Inside TokenTree::verify()) n_accepted_tokens: 0; stat.n_accepted_tokens: 3 

===================================DEBUG TOKEN TREE START====================================
[ACC] "\n\n" 1.00
├── [REJ] " Resources" 0.51
│   └── [REJ] "\n\n" 0.88
│       └── [REJ] " N" 0.75
│           └── [REJ] "IO" 0.92
│               └── [REJ] "\n\n" 0.65
│                   └── [REJ] " company" 0.70
└── [REJ] " N" 0.49
    └── [REJ] "IO" 0.99
        └── [REJ] " is" 0.54
            └── [REJ] " a" 0.88
                └── [REJ] " leading" 0.71

===================================DEBUG TOKEN TREE END====================================
     (Inside SpecTokenIterator::decode()) token queue:  N (#45), 

^^^^^^^^^^^^^^^^^^^TEXT: 

 (#271)^^^^^^^^^^^^^^^^^^^
 *******************************************************************OUTER LOOP 15:******************************************************************** 
(Inside TokenIterator::next()) The next token is: N (#45)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 1
 (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is: N (#45)
            (Inside TokenTree::draft()) Start forwarding in draft model: time 1
            (Inside TokenTree::draft()) Start forwarding in draft model: time 2
            (Inside TokenTree::draft()) Start forwarding in draft model: time 3
            (Inside TokenTree::draft()) Start forwarding in draft model: time 4
            (Inside TokenTree::draft()) Start forwarding in draft model: time 5
            (Inside TokenTree::draft()) n_saved_tokens: 5; n_nodes: 11
      (Inside TokenTree::generate_tokens()) Start forwarding in target model (slow!)
            (Inside TokenTree::verify()) n_generate_tokens: 1; stat.n_generated_tokens: 15 
            (Inside TokenTree::verify()) n_accepted_tokens: 0; stat.n_accepted_tokens: 3 

===================================DEBUG TOKEN TREE START====================================
[ACC] "N" 1.00
├── [REJ] "IO" 0.99
│   ├── [REJ] " is" 0.53
│   │   ├── [REJ] " a" 0.87
│   │   │   ├── [REJ] " leading" 0.70
│   │   │   │   ├── [REJ] " provider" 0.53
│   │   │   │   └── [REJ] " technology" 0.47
│   │   │   └── [REJ] " company" 0.30
│   │   └── [REJ] " an" 0.13
│   └── [REJ] "IO" 0.47
└── [REJ] "io" 0.01

===================================DEBUG TOKEN TREE END====================================
     (Inside SpecTokenIterator::decode()) token queue:   Resources (#16209), 

^^^^^^^^^^^^^^^^^^^TEXT: N (#45)^^^^^^^^^^^^^^^^^^^
 *******************************************************************OUTER LOOP 16:******************************************************************** 
(Inside TokenIterator::next()) The next token is:  Resources (#16209)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 1
 (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is:  Resources (#16209)
            (Inside TokenTree::draft()) Start forwarding in draft model: time 1
            (Inside TokenTree::draft()) Start forwarding in draft model: time 2
            (Inside TokenTree::draft()) Start forwarding in draft model: time 3
            (Inside TokenTree::draft()) Start forwarding in draft model: time 4
            (Inside TokenTree::draft()) Start forwarding in draft model: time 5
            (Inside TokenTree::draft()) Start forwarding in draft model: time 6
            (Inside TokenTree::draft()) Start forwarding in draft model: time 7
            (Inside TokenTree::draft()) Start forwarding in draft model: time 8
            (Inside TokenTree::draft()) Start forwarding in draft model: time 9
            (Inside TokenTree::draft()) n_saved_tokens: 9; n_nodes: 12
      (Inside TokenTree::generate_tokens()) Start forwarding in target model (slow!)
            (Inside TokenTree::verify()) n_generate_tokens: 3; stat.n_generated_tokens: 18 
            (Inside TokenTree::verify()) n_accepted_tokens: 2; stat.n_accepted_tokens: 5 

===================================DEBUG TOKEN TREE START====================================
[ACC] " Resources" 1.00
├── [ACC] "\n\n" 0.51
│   └── [ACC] "N" 0.70
│       └── [REJ] "IO" 0.89
│           └── [REJ] " Resources" 0.72
│               └── [REJ] " Co" 0.75
└── [REJ] " Co" 0.49
    ├── [REJ] " Resources" 0.61
    │   └── [REJ] " Co" 0.77
    │       └── [REJ] " Ltd" 0.90
    │           └── [REJ] " Co" 0.67
    └── [REJ] " Ltd" 0.39

===================================DEBUG TOKEN TREE END====================================
     (Inside SpecTokenIterator::decode()) token queue:  

 (#271),  N (#45),  ., (#2572), 

^^^^^^^^^^^^^^^^^^^TEXT:  Resources (#16209)^^^^^^^^^^^^^^^^^^^

[INFO ] prefill time: 13.699 s
[INFO ] prefill speed (6 tokens): 0.4379881743192934 tokens/s
[INFO ] decode speed (15 tokens): 0.04131127494856746 tokens/s
[INFO ] total speed: 0.055733075722672214 tokens/s
Speculative token tree statistics:
- 13 iterations, 18 generated tokens
- 1.385 tokens/iteration
- 6.769 draft-forwards/iteration
- Accept ratio: 3.650%
- Draft effective ratio: 5.682%

Process finished with exit code 0
```

Debug (batch=18, top-k=4):

```
/home/shuojiang/New-Projects/Attempt2/PowerServe/cmake-build-debug/bin/run --work-folder /home/shuojiang/New-Projects/Attempt2/PowerServe/models/ --model smallthinker-3b --draft-model smallthinker-0.5b --thread 4 --prompt "Please introduce the company NIO." --no-qnn
[INFO ] Compiled on: Feb  4 2025 at 17:04:46
[INFO ] Load model qwen2 ...
[INFO ] Load model qwen2 ...
[INFO ] after model init: [Memory(MB)] VMS: 4122, RSS: 4118
[INFO ] after platform init: [Memory(MB)] VMS: 7195, RSS: 4118
[INFO ] after attn init: [Memory(MB)] VMS: 7195, RSS: 4118
[DEBUG] special_bos         : 151643: <|endoftext|>
[DEBUG] special_eos         : 151645: <|im_end|>
[DEBUG] special_pad         : 151643: <|endoftext|>
[DEBUG] special_eot         : 151645: <|im_end|>
[INFO ] after tokenizer init: [Memory(MB)] VMS: 7245, RSS: 4169
[INFO ] seed: 0
[INFO ] after sampler init: [Memory(MB)] VMS: 7245, RSS: 4169
[INFO ] prompt      : "Please introduce the company NIO."
[INFO ] n_predicts  : 16
[INFO ] model arch  : qwen2
[INFO ] n_threads   : 4
[INFO ] batch_size   : 128
Please introduce the company NIO.
Not bug here1......
Not bug here2......
no bug inside 1......
no bug inside 2......
target model id: smallthinker_3b
no bug inside 2.3......
draft model id: smallthinker_500m
no bug inside 2.4......
no bug inside 2.5......
no bug inside 3......
no bug inside 4......
no bug inside 5......
no bug inside 6......
Not bug here3......
Not bug here4......
 *******************************************************************START OUTER LOOP 1:********************************************************************* 
(Inside TokenIterator::next()) The next token is: . (#13)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 1
 (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is: . (#13)
            (Inside TokenTree::draft()) Start forwarding in draft model: time 1
            (Inside TokenTree::draft()) Start forwarding in draft model: time 2
            (Inside TokenTree::draft()) Start forwarding in draft model: time 3
            (Inside TokenTree::draft()) Start forwarding in draft model: time 4
            (Inside TokenTree::draft()) Start forwarding in draft model: time 5
            (Inside TokenTree::draft()) Start forwarding in draft model: time 6
            (Inside TokenTree::draft()) n_saved_tokens: 6; n_nodes: 18
      (Inside TokenTree::generate_tokens()) Start forwarding in target model (slow!)
            (Inside TokenTree::verify()) n_generate_tokens: 5; stat.n_generated_tokens: 5 
            (Inside TokenTree::verify()) n_accepted_tokens: 4; stat.n_accepted_tokens: 4 

========================================DEBUG TOKEN TREE START=========================================
[ACC] "." 1.00
├── [ACC] " N" 0.70
│   └── [ACC] "IO" 0.99
│       ├── [ACC] " is" 0.76
│       │   ├── [ACC] " a" 0.78
│       │   │   ├── [REJ] " leading" 0.51
│       │   │   │   ├── [REJ] " provider" 0.37
│       │   │   │   ├── [REJ] " technology" 0.31
│       │   │   │   └── [REJ] " global" 0.20
│       │   │   ├── [REJ] " company" 0.19
│       │   │   ├── [REJ] " global" 0.18
│       │   │   └── [REJ] " Japanese" 0.12
│       │   └── [REJ] " an" 0.15
│       ├── [REJ] "," 0.10
│       └── [REJ] " was" 0.09
├── [REJ] " I" 0.14
├── [REJ] " It" 0.09
└── [REJ] " What" 0.07

========================================DEBUG TOKEN TREE END===========================================
     (Inside SpecTokenIterator::decode()) token queue:   N (#451),  IO (#3810),   is (#374),   a (#264),   Chinese (#8453), 
 *******************************************************************START OUTER LOOP 1:********************************************************************* 
(Inside TokenIterator::next()) The next token is:  N (#451)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 5
     (Inside SpecTokenIterator::decode()) Skip forward for this iteration!
^^^^^^^^^^^^^^^^^^^^^^^^TEXT:  N (#451)^^^^^^^^^^^^^^^^^^^^^^^^
 *******************************************************************END OUTER LOOP 1:***********************************************************************


 *******************************************************************START OUTER LOOP 2:********************************************************************* 
(Inside TokenIterator::next()) The next token is: IO (#3810)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 4
     (Inside SpecTokenIterator::decode()) Skip forward for this iteration!
^^^^^^^^^^^^^^^^^^^^^^^^TEXT: IO (#3810)^^^^^^^^^^^^^^^^^^^^^^^^
 *******************************************************************END OUTER LOOP 2:***********************************************************************


 *******************************************************************START OUTER LOOP 3:********************************************************************* 
(Inside TokenIterator::next()) The next token is:  is (#374)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 3
     (Inside SpecTokenIterator::decode()) Skip forward for this iteration!
^^^^^^^^^^^^^^^^^^^^^^^^TEXT:  is (#374)^^^^^^^^^^^^^^^^^^^^^^^^
 *******************************************************************END OUTER LOOP 3:***********************************************************************


 *******************************************************************START OUTER LOOP 4:********************************************************************* 
(Inside TokenIterator::next()) The next token is:  a (#264)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 2
     (Inside SpecTokenIterator::decode()) Skip forward for this iteration!
^^^^^^^^^^^^^^^^^^^^^^^^TEXT:  a (#264)^^^^^^^^^^^^^^^^^^^^^^^^
 *******************************************************************END OUTER LOOP 4:***********************************************************************


 *******************************************************************START OUTER LOOP 5:********************************************************************* 
(Inside TokenIterator::next()) The next token is:  Chinese (#8453)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 1
 (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is:  Chinese (#8453)
            (Inside TokenTree::draft()) Start forwarding in draft model: time 1
            (Inside TokenTree::draft()) Start forwarding in draft model: time 2
            (Inside TokenTree::draft()) Start forwarding in draft model: time 3
            (Inside TokenTree::draft()) n_saved_tokens: 3; n_nodes: 13
      (Inside TokenTree::generate_tokens()) Start forwarding in target model (slow!)
            (Inside TokenTree::verify()) n_generate_tokens: 1; stat.n_generated_tokens: 6 
            (Inside TokenTree::verify()) n_accepted_tokens: 0; stat.n_accepted_tokens: 4 

========================================DEBUG TOKEN TREE START=========================================
[ACC] " Chinese" 1.00
├── [REJ] " company" 0.61
│   ├── [REJ] " that" 0.51
│   │   ├── [REJ] " specializes" 0.44
│   │   ├── [REJ] " has" 0.24
│   │   ├── [REJ] " is" 0.17
│   │   └── [REJ] " develops" 0.14
│   ├── [REJ] " specializing" 0.23
│   ├── [REJ] "," 0.16
│   └── [REJ] " known" 0.10
├── [REJ] " technology" 0.16
├── [REJ] " tech" 0.14
└── [REJ] " multinational" 0.10

========================================DEBUG TOKEN TREE END===========================================
     (Inside SpecTokenIterator::decode()) token queue:   Resources (#16209), 

^^^^^^^^^^^^^^^^^^^^^^^^TEXT:  Chinese (#8453)^^^^^^^^^^^^^^^^^^^^^^^^
 *******************************************************************END OUTER LOOP 5:***********************************************************************


 *******************************************************************START OUTER LOOP 6:********************************************************************* 
(Inside TokenIterator::next()) The next token is:  Resources (#16209)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 1
 (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is:  Resources (#16209)
            (Inside TokenTree::draft()) Start forwarding in draft model: time 1
            (Inside TokenTree::draft()) Start forwarding in draft model: time 2
            (Inside TokenTree::draft()) n_saved_tokens: 2; n_nodes: 9
      (Inside TokenTree::generate_tokens()) Start forwarding in target model (slow!)
            (Inside TokenTree::verify()) n_generate_tokens: 1; stat.n_generated_tokens: 7 
            (Inside TokenTree::verify()) n_accepted_tokens: 0; stat.n_accepted_tokens: 4 

========================================DEBUG TOKEN TREE START=========================================
[ACC] " Resources" 1.00
├── [REJ] " Management" 0.44
│   ├── [REJ] " Company" 0.41
│   ├── [REJ] " Software" 0.24
│   ├── [REJ] " Information" 0.19
│   └── [REJ] " System" 0.16
├── [REJ] " Company" 0.30
├── [REJ] " and" 0.17
└── [REJ] " &" 0.09

========================================DEBUG TOKEN TREE END===========================================
     (Inside SpecTokenIterator::decode()) token queue:   Resources (#16209), 

^^^^^^^^^^^^^^^^^^^^^^^^TEXT:  Resources (#16209)^^^^^^^^^^^^^^^^^^^^^^^^
 *******************************************************************END OUTER LOOP 6:***********************************************************************


 *******************************************************************START OUTER LOOP 7:********************************************************************* 
(Inside TokenIterator::next()) The next token is:  Resources (#16209)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 1
 (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is:  Resources (#16209)
            (Inside TokenTree::draft()) Start forwarding in draft model: time 1
            (Inside TokenTree::draft()) Start forwarding in draft model: time 2
            (Inside TokenTree::draft()) Start forwarding in draft model: time 3
            (Inside TokenTree::draft()) n_saved_tokens: 3; n_nodes: 13
      (Inside TokenTree::generate_tokens()) Start forwarding in target model (slow!)
            (Inside TokenTree::verify()) n_generate_tokens: 1; stat.n_generated_tokens: 8 
            (Inside TokenTree::verify()) n_accepted_tokens: 0; stat.n_accepted_tokens: 4 

========================================DEBUG TOKEN TREE START=========================================
[ACC] " Resources" 1.00
├── [REJ] " Corporation" 0.33
│   ├── [REJ] " Limited" 0.35
│   ├── [REJ] " (" 0.26
│   ├── [REJ] "," 0.24
│   └── [REJ] " Ltd" 0.15
├── [REJ] " Company" 0.32
│   ├── [REJ] " Limited" 0.41
│   ├── [REJ] "," 0.25
│   ├── [REJ] " (" 0.17
│   └── [REJ] " Ltd" 0.17
├── [REJ] " Group" 0.23
└── [REJ] " company" 0.13

========================================DEBUG TOKEN TREE END===========================================
     (Inside SpecTokenIterator::decode()) token queue:   Resources (#16209), 

^^^^^^^^^^^^^^^^^^^^^^^^TEXT:  Resources (#16209)^^^^^^^^^^^^^^^^^^^^^^^^
 *******************************************************************END OUTER LOOP 7:***********************************************************************


 *******************************************************************START OUTER LOOP 8:********************************************************************* 
(Inside TokenIterator::next()) The next token is:  Resources (#16209)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 1
 (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is:  Resources (#16209)
            (Inside TokenTree::draft()) Start forwarding in draft model: time 1
            (Inside TokenTree::draft()) Start forwarding in draft model: time 2
            (Inside TokenTree::draft()) n_saved_tokens: 2; n_nodes: 9
      (Inside TokenTree::generate_tokens()) Start forwarding in target model (slow!)
            (Inside TokenTree::verify()) n_generate_tokens: 1; stat.n_generated_tokens: 9 
            (Inside TokenTree::verify()) n_accepted_tokens: 0; stat.n_accepted_tokens: 4 

========================================DEBUG TOKEN TREE START=========================================
[ACC] " Resources" 1.00
├── [REJ] " Company" 0.36
│   ├── [REJ] " Limited" 0.48
│   ├── [REJ] " Ltd" 0.22
│   ├── [REJ] "," 0.18
│   └── [REJ] " (" 0.12
├── [REJ] " Corporation" 0.31
├── [REJ] " (" 0.19
└── [REJ] "," 0.14

========================================DEBUG TOKEN TREE END===========================================
     (Inside SpecTokenIterator::decode()) token queue:   Resources (#16209), 

^^^^^^^^^^^^^^^^^^^^^^^^TEXT:  Resources (#16209)^^^^^^^^^^^^^^^^^^^^^^^^
 *******************************************************************END OUTER LOOP 8:***********************************************************************


 *******************************************************************START OUTER LOOP 9:********************************************************************* 
(Inside TokenIterator::next()) The next token is:  Resources (#16209)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 1
 (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is:  Resources (#16209)
            (Inside TokenTree::draft()) Start forwarding in draft model: time 1
            (Inside TokenTree::draft()) Start forwarding in draft model: time 2
            (Inside TokenTree::draft()) Start forwarding in draft model: time 3
            (Inside TokenTree::draft()) Start forwarding in draft model: time 4
            (Inside TokenTree::draft()) Start forwarding in draft model: time 5
            (Inside TokenTree::draft()) Start forwarding in draft model: time 6
            (Inside TokenTree::draft()) Start forwarding in draft model: time 7
            (Inside TokenTree::draft()) Start forwarding in draft model: time 8
            (Inside TokenTree::draft()) Start forwarding in draft model: time 9
            (Inside TokenTree::draft()) Start forwarding in draft model: time 10
            (Inside TokenTree::draft()) Start forwarding in draft model: time 11
            (Inside TokenTree::draft()) n_saved_tokens: 11; n_nodes: 18
      (Inside TokenTree::generate_tokens()) Start forwarding in target model (slow!)
            (Inside TokenTree::verify()) n_generate_tokens: 1; stat.n_generated_tokens: 10 
            (Inside TokenTree::verify()) n_accepted_tokens: 0; stat.n_accepted_tokens: 4 

========================================DEBUG TOKEN TREE START=========================================
[ACC] " Resources" 1.00
├── [REJ] " Resources" 0.54
│   ├── [REJ] " Resources" 0.75
│   │   └── [REJ] " Resources" 0.82
│   │       └── [REJ] " Resources" 0.89
│   │           └── [REJ] " Resources" 0.93
│   │               └── [REJ] " Resources" 0.95
│   │                   └── [REJ] " Resources" 0.94
│   │                       └── [REJ] " Resources" 0.94
│   │                           └── [REJ] " Resources" 0.95
│   │                               └── [REJ] " Resources" 0.96
│   │                                   └── [REJ] " Resources" 0.96
│   ├── [REJ] "." 0.09
│   ├── [REJ] " resources" 0.09
│   └── [REJ] " Company" 0.07
├── [REJ] " Company" 0.18
├── [REJ] " Corporation" 0.15
└── [REJ] " company" 0.14

========================================DEBUG TOKEN TREE END===========================================
     (Inside SpecTokenIterator::decode()) token queue:   Co (#3539), 

^^^^^^^^^^^^^^^^^^^^^^^^TEXT:  Resources (#16209)^^^^^^^^^^^^^^^^^^^^^^^^
 *******************************************************************END OUTER LOOP 9:***********************************************************************


 *******************************************************************START OUTER LOOP 10:********************************************************************* 
(Inside TokenIterator::next()) The next token is:  Co (#3539)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 1
 (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is:  Co (#3539)
            (Inside TokenTree::draft()) Start forwarding in draft model: time 1
            (Inside TokenTree::draft()) Start forwarding in draft model: time 2
            (Inside TokenTree::draft()) Start forwarding in draft model: time 3
            (Inside TokenTree::draft()) n_saved_tokens: 3; n_nodes: 13
      (Inside TokenTree::generate_tokens()) Start forwarding in target model (slow!)
            (Inside TokenTree::verify()) n_generate_tokens: 1; stat.n_generated_tokens: 11 
            (Inside TokenTree::verify()) n_accepted_tokens: 0; stat.n_accepted_tokens: 4 

========================================DEBUG TOKEN TREE START=========================================
[ACC] " Co" 1.00
├── [REJ] "." 0.40
│   ├── [REJ] " Ltd" 0.83
│   │   ├── [REJ] "." 0.51
│   │   ├── [REJ] ".," 0.31
│   │   ├── [REJ] "," 0.13
│   │   └── [REJ] " (" 0.05
│   ├── [REJ] " (" 0.08
│   ├── [REJ] " Inc" 0.05
│   └── [REJ] " Co" 0.04
├── [REJ] " Ltd" 0.26
├── [REJ] ".," 0.25
└── [REJ] "," 0.08

========================================DEBUG TOKEN TREE END===========================================
     (Inside SpecTokenIterator::decode()) token queue:   Resources (#16209), 

^^^^^^^^^^^^^^^^^^^^^^^^TEXT:  Co (#3539)^^^^^^^^^^^^^^^^^^^^^^^^
 *******************************************************************END OUTER LOOP 10:***********************************************************************


 *******************************************************************START OUTER LOOP 11:********************************************************************* 
(Inside TokenIterator::next()) The next token is:  Resources (#16209)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 1
 (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is:  Resources (#16209)
            (Inside TokenTree::draft()) Start forwarding in draft model: time 1
            (Inside TokenTree::draft()) Start forwarding in draft model: time 2
            (Inside TokenTree::draft()) Start forwarding in draft model: time 3
            (Inside TokenTree::draft()) Start forwarding in draft model: time 4
            (Inside TokenTree::draft()) Start forwarding in draft model: time 5
            (Inside TokenTree::draft()) Start forwarding in draft model: time 6
            (Inside TokenTree::draft()) Start forwarding in draft model: time 7
            (Inside TokenTree::draft()) Start forwarding in draft model: time 8
            (Inside TokenTree::draft()) Start forwarding in draft model: time 9
            (Inside TokenTree::draft()) Start forwarding in draft model: time 10
            (Inside TokenTree::draft()) n_saved_tokens: 10; n_nodes: 18
      (Inside TokenTree::generate_tokens()) Start forwarding in target model (slow!)
            (Inside TokenTree::verify()) n_generate_tokens: 1; stat.n_generated_tokens: 12 
            (Inside TokenTree::verify()) n_accepted_tokens: 0; stat.n_accepted_tokens: 4 

========================================DEBUG TOKEN TREE START=========================================
[ACC] " Resources" 1.00
├── [REJ] " Resources" 0.85
│   ├── [REJ] " Resources" 0.76
│   │   ├── [REJ] " Resources" 0.78
│   │   │   ├── [REJ] " Resources" 0.72
│   │   │   │   └── [REJ] " Resources" 0.81
│   │   │   │       └── [REJ] " Resources" 0.88
│   │   │   │           └── [REJ] " Resources" 0.92
│   │   │   │               └── [REJ] " Resources" 0.94
│   │   │   │                   └── [REJ] " Resources" 0.94
│   │   │   │                       └── [REJ] " Resources" 0.94
│   │   │   └── [REJ] " Co" 0.15
│   │   └── [REJ] " Co" 0.10
│   ├── [REJ] " Co" 0.14
│   ├── [REJ] " Corporation" 0.06
│   └── [REJ] " Company" 0.05
├── [REJ] "Resources" 0.06
└── [REJ] " Corporation" 0.05

========================================DEBUG TOKEN TREE END===========================================
     (Inside SpecTokenIterator::decode()) token queue:   Co (#3539), 

^^^^^^^^^^^^^^^^^^^^^^^^TEXT:  Resources (#16209)^^^^^^^^^^^^^^^^^^^^^^^^
 *******************************************************************END OUTER LOOP 11:***********************************************************************


 *******************************************************************START OUTER LOOP 12:********************************************************************* 
(Inside TokenIterator::next()) The next token is:  Co (#3539)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 1
 (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is:  Co (#3539)
            (Inside TokenTree::draft()) Start forwarding in draft model: time 1
            (Inside TokenTree::draft()) Start forwarding in draft model: time 2
            (Inside TokenTree::draft()) Start forwarding in draft model: time 3
            (Inside TokenTree::draft()) Start forwarding in draft model: time 4
            (Inside TokenTree::draft()) n_saved_tokens: 4; n_nodes: 17
      (Inside TokenTree::generate_tokens()) Start forwarding in target model (slow!)
            (Inside TokenTree::verify()) n_generate_tokens: 3; stat.n_generated_tokens: 15 
            (Inside TokenTree::verify()) n_accepted_tokens: 2; stat.n_accepted_tokens: 6 

========================================DEBUG TOKEN TREE START=========================================
[ACC] " Co" 1.00
├── [REJ] "." 0.27
│   ├── [REJ] " Ltd" 0.44
│   ├── [REJ] " N" 0.27
│   ├── [REJ] " (" 0.15
│   └── [REJ] " Co" 0.14
├── [REJ] " Ltd" 0.25
│   ├── [REJ] "." 0.33
│   ├── [REJ] " company" 0.28
│   ├── [REJ] "," 0.23
│   └── [REJ] " Company" 0.16
├── [ACC] " Resources" 0.25
│   ├── [ACC] " Resources" 0.46
│   ├── [REJ] " Co" 0.41
│   ├── [REJ] " Company" 0.07
│   └── [REJ] "." 0.05
└── [REJ] "," 0.23

========================================DEBUG TOKEN TREE END===========================================
     (Inside SpecTokenIterator::decode()) token queue:   Resources (#16209),   Resources (#16209),   Resources (#16209), 

^^^^^^^^^^^^^^^^^^^^^^^^TEXT:  Co (#3539)^^^^^^^^^^^^^^^^^^^^^^^^
 *******************************************************************END OUTER LOOP 12:***********************************************************************


 *******************************************************************START OUTER LOOP 13:********************************************************************* 
(Inside TokenIterator::next()) The next token is:  Resources (#16209)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 3
     (Inside SpecTokenIterator::decode()) Skip forward for this iteration!
^^^^^^^^^^^^^^^^^^^^^^^^TEXT:  Resources (#16209)^^^^^^^^^^^^^^^^^^^^^^^^
 *******************************************************************END OUTER LOOP 13:***********************************************************************


 *******************************************************************START OUTER LOOP 14:********************************************************************* 
(Inside TokenIterator::next()) The next token is:  Resources (#16209)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 2
     (Inside SpecTokenIterator::decode()) Skip forward for this iteration!
^^^^^^^^^^^^^^^^^^^^^^^^TEXT:  Resources (#16209)^^^^^^^^^^^^^^^^^^^^^^^^
 *******************************************************************END OUTER LOOP 14:***********************************************************************


 *******************************************************************START OUTER LOOP 15:********************************************************************* 
(Inside TokenIterator::next()) The next token is:  Resources (#16209)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 1
 (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is:  Resources (#16209)
            (Inside TokenTree::draft()) Start forwarding in draft model: time 1
            (Inside TokenTree::draft()) Start forwarding in draft model: time 2
            (Inside TokenTree::draft()) Start forwarding in draft model: time 3
            (Inside TokenTree::draft()) Start forwarding in draft model: time 4
            (Inside TokenTree::draft()) Start forwarding in draft model: time 5
            (Inside TokenTree::draft()) n_saved_tokens: 5; n_nodes: 18
      (Inside TokenTree::generate_tokens()) Start forwarding in target model (slow!)
            (Inside TokenTree::verify()) n_generate_tokens: 2; stat.n_generated_tokens: 17 
            (Inside TokenTree::verify()) n_accepted_tokens: 1; stat.n_accepted_tokens: 7 

========================================DEBUG TOKEN TREE START=========================================
[ACC] " Resources" 1.00
├── [REJ] " Resources" 0.49
│   ├── [REJ] " Resources" 0.66
│   │   ├── [REJ] " Resources" 0.78
│   │   │   ├── [REJ] " Resources" 0.83
│   │   │   │   └── [REJ] " Resources" 0.88
│   │   │   ├── [REJ] "." 0.06
│   │   │   ├── [REJ] " N" 0.05
│   │   │   └── [REJ] "\n\n" 0.05
│   │   ├── [REJ] " Co" 0.08
│   │   ├── [REJ] " N" 0.07
│   │   └── [REJ] "." 0.07
│   ├── [REJ] " Co" 0.19
│   ├── [REJ] "." 0.09
│   └── [REJ] " N" 0.06
├── [ACC] " Co" 0.39
├── [REJ] "." 0.06
└── [REJ] " Company" 0.06

========================================DEBUG TOKEN TREE END===========================================
     (Inside SpecTokenIterator::decode()) token queue:   Co (#3539),  

 (#271), 

^^^^^^^^^^^^^^^^^^^^^^^^TEXT:  Resources (#16209)^^^^^^^^^^^^^^^^^^^^^^^^
 *******************************************************************END OUTER LOOP 15:***********************************************************************



[INFO ] prefill time: 13.324 s
[INFO ] prefill speed (6 tokens): 0.4503152206544581 tokens/s
[INFO ] decode speed (15 tokens): 0.04110219650138103 tokens/s
[INFO ] total speed: 0.05551619486713124 tokens/s
Speculative token tree statistics:
- 10 iterations, 17 generated tokens
- 1.700 tokens/iteration
- 4.900 draft-forwards/iteration
- Accept ratio: 5.147%
- Draft effective ratio: 14.286%

Process finished with exit code 0
```

Debug (batch = 18, top_k = 8):

```
/home/shuojiang/New-Projects/Attempt2/PowerServe/cmake-build-debug/bin/run --work-folder /home/shuojiang/New-Projects/Attempt2/PowerServe/models/ --model smallthinker-3b --draft-model smallthinker-0.5b --thread 4 --prompt "Please introduce the company NIO." --no-qnn
[INFO ] Compiled on: Feb  4 2025 at 17:26:35
[INFO ] Load model qwen2 ...
[INFO ] Load model qwen2 ...
[INFO ] after model init: [Memory(MB)] VMS: 4122, RSS: 4118
[INFO ] after platform init: [Memory(MB)] VMS: 7195, RSS: 4119
[INFO ] after attn init: [Memory(MB)] VMS: 7195, RSS: 4119
[DEBUG] special_bos         : 151643: <|endoftext|>
[DEBUG] special_eos         : 151645: <|im_end|>
[DEBUG] special_pad         : 151643: <|endoftext|>
[DEBUG] special_eot         : 151645: <|im_end|>
[INFO ] after tokenizer init: [Memory(MB)] VMS: 7245, RSS: 4169
[INFO ] seed: 0
[INFO ] after sampler init: [Memory(MB)] VMS: 7245, RSS: 4169
[INFO ] prompt      : "Please introduce the company NIO."
[INFO ] n_predicts  : 16
[INFO ] model arch  : qwen2
[INFO ] n_threads   : 4
[INFO ] batch_size   : 128
Please introduce the company NIO.
Not bug here1......
Not bug here2......
no bug inside 1......
no bug inside 2......
target model id: smallthinker_3b
no bug inside 2.3......
draft model id: smallthinker_500m
no bug inside 2.4......
no bug inside 2.5......
no bug inside 3......
no bug inside 4......
no bug inside 5......
no bug inside 6......
Not bug here3......
Not bug here4......
 *******************************************************************START OUTER LOOP 1:********************************************************************* 
(Inside TokenIterator::next()) The next token is: . (#13)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 1
 (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is: . (#13)
            (Inside TokenTree::draft()) Start forwarding in draft model: time 1
            (Inside TokenTree::draft()) Start forwarding in draft model: time 2
            (Inside TokenTree::draft()) Start forwarding in draft model: time 3
            (Inside TokenTree::draft()) Start forwarding in draft model: time 4
            (Inside TokenTree::draft()) Start forwarding in draft model: time 5
            (Inside TokenTree::draft()) n_saved_tokens: 5; n_nodes: 18
      (Inside TokenTree::generate_tokens()) Start forwarding in target model (slow!)
            (Inside TokenTree::verify()) Generated token by target model: (#451)
            (Inside TokenTree::verify()) Accepted token by target model: (#451)
            (Inside TokenTree::verify()) Generated token by target model: (#3810)
            (Inside TokenTree::verify()) Accepted token by target model: (#3810)
            (Inside TokenTree::verify()) Generated token by target model: (#3810)
            (Inside TokenTree::verify()) n_generate_tokens: 3; stat.n_generated_tokens: 3 
            (Inside TokenTree::verify()) n_accepted_tokens: 2; stat.n_accepted_tokens: 2 

========================================DEBUG TOKEN TREE START=========================================
[ACC] "." 1.00
├── [ACC] " N" 0.60
│   └── [ACC] "IO" 0.98
│       ├── [REJ] " is" 0.68
│       │   ├── [REJ] " a" 0.74
│       │   │   ├── [REJ] " leading" 0.37
│       │   │   ├── [REJ] " company" 0.14
│       │   │   └── [REJ] " global" 0.14
│       │   └── [REJ] " an" 0.14
│       ├── [REJ] "," 0.09
│       └── [REJ] " was" 0.08
├── [REJ] " I" 0.12
├── [REJ] " It" 0.07
├── [REJ] " What" 0.06
├── [REJ] " Founded" 0.05
├── [REJ] " How" 0.04
├── [REJ] " The" 0.03
└── [REJ] " Let" 0.03

========================================DEBUG TOKEN TREE END===========================================
     (Inside SpecTokenIterator::decode()) token queue:   N (#451),  IO (#3810),  IO (#3810), 
 *******************************************************************START OUTER LOOP 1:********************************************************************* 
(Inside TokenIterator::next()) The next token is:  N (#451)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 3
     (Inside SpecTokenIterator::decode()) Skip forward for this iteration!
^^^^^^^^^^^^^^^^^^^^^^^^TEXT:  N (#451)^^^^^^^^^^^^^^^^^^^^^^^^
 *******************************************************************END OUTER LOOP 1:***********************************************************************


 *******************************************************************START OUTER LOOP 2:********************************************************************* 
(Inside TokenIterator::next()) The next token is: IO (#3810)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 2
     (Inside SpecTokenIterator::decode()) Skip forward for this iteration!
^^^^^^^^^^^^^^^^^^^^^^^^TEXT: IO (#3810)^^^^^^^^^^^^^^^^^^^^^^^^
 *******************************************************************END OUTER LOOP 2:***********************************************************************


 *******************************************************************START OUTER LOOP 3:********************************************************************* 
(Inside TokenIterator::next()) The next token is: IO (#3810)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 1
 (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is: IO (#3810)
            (Inside TokenTree::draft()) Start forwarding in draft model: time 1
            (Inside TokenTree::draft()) Start forwarding in draft model: time 2
            (Inside TokenTree::draft()) n_saved_tokens: 2; n_nodes: 17
      (Inside TokenTree::generate_tokens()) Start forwarding in target model (slow!)
            (Inside TokenTree::verify()) Generated token by target model: (#16209)
            (Inside TokenTree::verify()) n_generate_tokens: 1; stat.n_generated_tokens: 4 
            (Inside TokenTree::verify()) n_accepted_tokens: 0; stat.n_accepted_tokens: 2 

========================================DEBUG TOKEN TREE START=========================================
[ACC] "IO" 1.00
├── [REJ] " is" 0.36
│   ├── [REJ] " a" 0.53
│   ├── [REJ] " the" 0.17
│   ├── [REJ] " an" 0.15
│   ├── [REJ] " one" 0.05
│   ├── [REJ] " not" 0.03
│   ├── [REJ] " N" 0.03
│   ├── [REJ] " located" 0.02
│   └── [REJ] " based" 0.02
├── [REJ] "," 0.12
├── [REJ] "\n\n" 0.12
├── [REJ] " has" 0.10
├── [REJ] ".com" 0.08
├── [REJ] "." 0.08
├── [REJ] ":" 0.08
└── [REJ] "N" 0.06

========================================DEBUG TOKEN TREE END===========================================
     (Inside SpecTokenIterator::decode()) token queue:   Resources (#16209), 

^^^^^^^^^^^^^^^^^^^^^^^^TEXT: IO (#3810)^^^^^^^^^^^^^^^^^^^^^^^^
 *******************************************************************END OUTER LOOP 3:***********************************************************************


 *******************************************************************START OUTER LOOP 4:********************************************************************* 
(Inside TokenIterator::next()) The next token is:  Resources (#16209)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 1
 (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is:  Resources (#16209)
            (Inside TokenTree::draft()) Start forwarding in draft model: time 1
            (Inside TokenTree::draft()) Start forwarding in draft model: time 2
            (Inside TokenTree::draft()) Start forwarding in draft model: time 3
            (Inside TokenTree::draft()) n_saved_tokens: 3; n_nodes: 18
      (Inside TokenTree::generate_tokens()) Start forwarding in target model (slow!)
            (Inside TokenTree::verify()) Generated token by target model: (#3539)
            (Inside TokenTree::verify()) n_generate_tokens: 1; stat.n_generated_tokens: 5 
            (Inside TokenTree::verify()) n_accepted_tokens: 0; stat.n_accepted_tokens: 2 

========================================DEBUG TOKEN TREE START=========================================
[ACC] " Resources" 1.00
├── [REJ] " is" 0.38
│   ├── [REJ] " a" 0.54
│   │   ├── [REJ] " leading" 0.39
│   │   ├── [REJ] " company" 0.19
│   │   ├── [REJ] " global" 0.11
│   │   └── [REJ] " subsidiary" 0.09
│   ├── [REJ] " the" 0.14
│   ├── [REJ] " an" 0.12
│   ├── [REJ] " one" 0.06
│   └── [REJ] " located" 0.05
├── [REJ] "," 0.15
├── [REJ] " Inc" 0.10
├── [REJ] "\n\n" 0.09
├── [REJ] " Ltd" 0.09
├── [REJ] " LLC" 0.07
├── [REJ] " Limited" 0.06
└── [REJ] " (" 0.06

========================================DEBUG TOKEN TREE END===========================================
     (Inside SpecTokenIterator::decode()) token queue:   Co (#3539), 

^^^^^^^^^^^^^^^^^^^^^^^^TEXT:  Resources (#16209)^^^^^^^^^^^^^^^^^^^^^^^^
 *******************************************************************END OUTER LOOP 4:***********************************************************************


 *******************************************************************START OUTER LOOP 5:********************************************************************* 
(Inside TokenIterator::next()) The next token is:  Co (#3539)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 1
 (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is:  Co (#3539)
            (Inside TokenTree::draft()) Start forwarding in draft model: time 1
            (Inside TokenTree::draft()) Start forwarding in draft model: time 2
            (Inside TokenTree::draft()) n_saved_tokens: 2; n_nodes: 17
      (Inside TokenTree::generate_tokens()) Start forwarding in target model (slow!)
            (Inside TokenTree::verify()) Generated token by target model: (#16209)
            (Inside TokenTree::verify()) n_generate_tokens: 1; stat.n_generated_tokens: 6 
            (Inside TokenTree::verify()) n_accepted_tokens: 0; stat.n_accepted_tokens: 2 

========================================DEBUG TOKEN TREE START=========================================
[ACC] " Co" 1.00
├── [REJ] "." 0.35
│   ├── [REJ] " Ltd" 0.55
│   ├── [REJ] " is" 0.16
│   ├── [REJ] " (" 0.10
│   ├── [REJ] " Inc" 0.05
│   ├── [REJ] " N" 0.04
│   ├── [REJ] " LLC" 0.04
│   ├── [REJ] " Limited" 0.03
│   └── [REJ] " has" 0.03
├── [REJ] ".," 0.24
├── [REJ] " Ltd" 0.23
├── [REJ] "," 0.05
├── [REJ] ".\n\n" 0.05
├── [REJ] " is" 0.03
├── [REJ] ".\n" 0.02
└── [REJ] " (" 0.02

========================================DEBUG TOKEN TREE END===========================================
     (Inside SpecTokenIterator::decode()) token queue:   Resources (#16209), 

^^^^^^^^^^^^^^^^^^^^^^^^TEXT:  Co (#3539)^^^^^^^^^^^^^^^^^^^^^^^^
 *******************************************************************END OUTER LOOP 5:***********************************************************************


 *******************************************************************START OUTER LOOP 6:********************************************************************* 
(Inside TokenIterator::next()) The next token is:  Resources (#16209)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 1
 (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is:  Resources (#16209)
            (Inside TokenTree::draft()) Start forwarding in draft model: time 1
            (Inside TokenTree::draft()) n_saved_tokens: 1; n_nodes: 9
      (Inside TokenTree::generate_tokens()) Start forwarding in target model (slow!)
            (Inside TokenTree::verify()) Generated token by target model: (#16209)
            (Inside TokenTree::verify()) n_generate_tokens: 1; stat.n_generated_tokens: 7 
            (Inside TokenTree::verify()) n_accepted_tokens: 0; stat.n_accepted_tokens: 2 

========================================DEBUG TOKEN TREE START=========================================
[ACC] " Resources" 1.00
├── [REJ] " is" 0.15
├── [REJ] " Inc" 0.14
├── [REJ] " Corporation" 0.13
├── [REJ] "\n\n" 0.12
├── [REJ] " Company" 0.12
├── [REJ] " Ltd" 0.11
├── [REJ] " Co" 0.11
└── [REJ] "," 0.11

========================================DEBUG TOKEN TREE END===========================================
     (Inside SpecTokenIterator::decode()) token queue:   Resources (#16209), 

^^^^^^^^^^^^^^^^^^^^^^^^TEXT:  Resources (#16209)^^^^^^^^^^^^^^^^^^^^^^^^
 *******************************************************************END OUTER LOOP 6:***********************************************************************


 *******************************************************************START OUTER LOOP 7:********************************************************************* 
(Inside TokenIterator::next()) The next token is:  Resources (#16209)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 1
 (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is:  Resources (#16209)
            (Inside TokenTree::draft()) Start forwarding in draft model: time 1
            (Inside TokenTree::draft()) Start forwarding in draft model: time 2
            (Inside TokenTree::draft()) n_saved_tokens: 2; n_nodes: 17
      (Inside TokenTree::generate_tokens()) Start forwarding in target model (slow!)
            (Inside TokenTree::verify()) Generated token by target model: (#16209)
            (Inside TokenTree::verify()) Accepted token by target model: (#16209)
            (Inside TokenTree::verify()) Generated token by target model: (#16209)
            (Inside TokenTree::verify()) Accepted token by target model: (#16209)
            (Inside TokenTree::verify()) Generated token by target model: (#16209)
            (Inside TokenTree::verify()) n_generate_tokens: 3; stat.n_generated_tokens: 10 
            (Inside TokenTree::verify()) n_accepted_tokens: 2; stat.n_accepted_tokens: 4 

========================================DEBUG TOKEN TREE START=========================================
[ACC] " Resources" 1.00
├── [ACC] " Resources" 0.28
│   ├── [ACC] " Resources" 0.61
│   ├── [REJ] "\n\n" 0.14
│   ├── [REJ] " is" 0.06
│   ├── [REJ] " N" 0.05
│   ├── [REJ] "." 0.04
│   ├── [REJ] "Resources" 0.04
│   ├── [REJ] ".\n\n" 0.04
│   └── [REJ] " Industries" 0.04
├── [REJ] " Inc" 0.15
├── [REJ] "\n\n" 0.12
├── [REJ] " Group" 0.10
├── [REJ] " Co" 0.10
├── [REJ] " Corporation" 0.09
├── [REJ] " is" 0.08
└── [REJ] " Ltd" 0.07

========================================DEBUG TOKEN TREE END===========================================
     (Inside SpecTokenIterator::decode()) token queue:   Resources (#16209),   Resources (#16209),   Resources (#16209), 

^^^^^^^^^^^^^^^^^^^^^^^^TEXT:  Resources (#16209)^^^^^^^^^^^^^^^^^^^^^^^^
 *******************************************************************END OUTER LOOP 7:***********************************************************************


 *******************************************************************START OUTER LOOP 8:********************************************************************* 
(Inside TokenIterator::next()) The next token is:  Resources (#16209)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 3
     (Inside SpecTokenIterator::decode()) Skip forward for this iteration!
^^^^^^^^^^^^^^^^^^^^^^^^TEXT:  Resources (#16209)^^^^^^^^^^^^^^^^^^^^^^^^
 *******************************************************************END OUTER LOOP 8:***********************************************************************


 *******************************************************************START OUTER LOOP 9:********************************************************************* 
(Inside TokenIterator::next()) The next token is:  Resources (#16209)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 2
     (Inside SpecTokenIterator::decode()) Skip forward for this iteration!
^^^^^^^^^^^^^^^^^^^^^^^^TEXT:  Resources (#16209)^^^^^^^^^^^^^^^^^^^^^^^^
 *******************************************************************END OUTER LOOP 9:***********************************************************************


 *******************************************************************START OUTER LOOP 10:********************************************************************* 
(Inside TokenIterator::next()) The next token is:  Resources (#16209)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 1
 (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is:  Resources (#16209)
            (Inside TokenTree::draft()) Start forwarding in draft model: time 1
            (Inside TokenTree::draft()) Start forwarding in draft model: time 2
            (Inside TokenTree::draft()) Start forwarding in draft model: time 3
            (Inside TokenTree::draft()) Start forwarding in draft model: time 4
            (Inside TokenTree::draft()) Start forwarding in draft model: time 5
            (Inside TokenTree::draft()) Start forwarding in draft model: time 6
            (Inside TokenTree::draft()) Start forwarding in draft model: time 7
            (Inside TokenTree::draft()) Start forwarding in draft model: time 8
            (Inside TokenTree::draft()) Start forwarding in draft model: time 9
            (Inside TokenTree::draft()) Start forwarding in draft model: time 10
            (Inside TokenTree::draft()) Start forwarding in draft model: time 11
            (Inside TokenTree::draft()) n_saved_tokens: 11; n_nodes: 18
      (Inside TokenTree::generate_tokens()) Start forwarding in target model (slow!)
            (Inside TokenTree::verify()) Generated token by target model: (#3539)
            (Inside TokenTree::verify()) n_generate_tokens: 1; stat.n_generated_tokens: 11 
            (Inside TokenTree::verify()) n_accepted_tokens: 0; stat.n_accepted_tokens: 4 

========================================DEBUG TOKEN TREE START=========================================
[ACC] " Resources" 1.00
├── [REJ] " Resources" 0.63
│   ├── [REJ] " Resources" 0.76
│   │   ├── [REJ] " Resources" 0.86
│   │   │   └── [REJ] " Resources" 0.91
│   │   │       └── [REJ] " Resources" 0.90
│   │   │           └── [REJ] " Resources" 0.90
│   │   │               └── [REJ] " Resources" 0.89
│   │   │                   └── [REJ] " Resources" 0.90
│   │   │                       └── [REJ] " Resources" 0.91
│   │   │                           └── [REJ] " Resources" 0.91
│   │   │                               └── [REJ] " Resources" 0.90
│   │   └── [REJ] "\n\n" 0.06
│   ├── [REJ] "\n\n" 0.11
│   └── [REJ] " N" 0.06
├── [REJ] "\n\n" 0.18
├── [REJ] " N" 0.08
└── [REJ] "Resources" 0.03

========================================DEBUG TOKEN TREE END===========================================
     (Inside SpecTokenIterator::decode()) token queue:   Co (#3539), 

^^^^^^^^^^^^^^^^^^^^^^^^TEXT:  Resources (#16209)^^^^^^^^^^^^^^^^^^^^^^^^
 *******************************************************************END OUTER LOOP 10:***********************************************************************


 *******************************************************************START OUTER LOOP 11:********************************************************************* 
(Inside TokenIterator::next()) The next token is:  Co (#3539)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 1
 (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is:  Co (#3539)
            (Inside TokenTree::draft()) Start forwarding in draft model: time 1
            (Inside TokenTree::draft()) Start forwarding in draft model: time 2
            (Inside TokenTree::draft()) Start forwarding in draft model: time 3
            (Inside TokenTree::draft()) Start forwarding in draft model: time 4
            (Inside TokenTree::draft()) Start forwarding in draft model: time 5
            (Inside TokenTree::draft()) Start forwarding in draft model: time 6
            (Inside TokenTree::draft()) n_saved_tokens: 6; n_nodes: 18
      (Inside TokenTree::generate_tokens()) Start forwarding in target model (slow!)
            (Inside TokenTree::verify()) Generated token by target model: (#12324)
            (Inside TokenTree::verify()) n_generate_tokens: 1; stat.n_generated_tokens: 12 
            (Inside TokenTree::verify()) n_accepted_tokens: 0; stat.n_accepted_tokens: 4 

========================================DEBUG TOKEN TREE START=========================================
[ACC] " Co" 1.00
├── [REJ] " Resources" 0.54
│   ├── [REJ] " Resources" 0.83
│   │   ├── [REJ] " Resources" 0.85
│   │   │   └── [REJ] " Resources" 0.85
│   │   │       └── [REJ] " Resources" 0.84
│   │   │           ├── [REJ] " Resources" 0.68
│   │   │           ├── [REJ] " Co" 0.15
│   │   │           └── [REJ] "\n\n" 0.10
│   │   └── [REJ] " Co" 0.06
│   └── [REJ] "\n\n" 0.04
├── [REJ] "\n\n" 0.16
├── [REJ] " N" 0.08
├── [REJ] "Resources" 0.06
├── [REJ] "." 0.06
├── [REJ] "," 0.04
├── [REJ] " is" 0.04
└── [REJ] ".\n\n" 0.03

========================================DEBUG TOKEN TREE END===========================================
     (Inside SpecTokenIterator::decode()) token queue:   Ltd (#12324), 

^^^^^^^^^^^^^^^^^^^^^^^^TEXT:  Co (#3539)^^^^^^^^^^^^^^^^^^^^^^^^
 *******************************************************************END OUTER LOOP 11:***********************************************************************


 *******************************************************************START OUTER LOOP 12:********************************************************************* 
(Inside TokenIterator::next()) The next token is:  Ltd (#12324)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 1
 (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is:  Ltd (#12324)
            (Inside TokenTree::draft()) Start forwarding in draft model: time 1
            (Inside TokenTree::draft()) Start forwarding in draft model: time 2
            (Inside TokenTree::draft()) Start forwarding in draft model: time 3
            (Inside TokenTree::draft()) n_saved_tokens: 3; n_nodes: 18
      (Inside TokenTree::generate_tokens()) Start forwarding in target model (slow!)
            (Inside TokenTree::verify()) Generated token by target model: (#13)
            (Inside TokenTree::verify()) Accepted token by target model: (#13)
            (Inside TokenTree::verify()) Generated token by target model: (#320)
            (Inside TokenTree::verify()) n_generate_tokens: 2; stat.n_generated_tokens: 14 
            (Inside TokenTree::verify()) n_accepted_tokens: 1; stat.n_accepted_tokens: 5 

========================================DEBUG TOKEN TREE START=========================================
[ACC] " Ltd" 1.00
├── [REJ] " Resources" 0.28
│   ├── [REJ] " Resources" 0.78
│   │   ├── [REJ] " Resources" 0.81
│   │   ├── [REJ] " Co" 0.08
│   │   ├── [REJ] "\n\n" 0.03
│   │   └── [REJ] " Industries" 0.02
│   ├── [REJ] " Co" 0.06
│   ├── [REJ] " Industries" 0.04
│   ├── [REJ] "\n\n" 0.04
│   └── [REJ] "Resources" 0.03
├── [REJ] "\n\n" 0.17
├── [REJ] " N" 0.15
├── [ACC] "." 0.13
├── [REJ] " is" 0.09
├── [REJ] " Co" 0.06
├── [REJ] "," 0.06
└── [REJ] " Ltd" 0.06

========================================DEBUG TOKEN TREE END===========================================
     (Inside SpecTokenIterator::decode()) token queue:  . (#13),   ( (#320), 

^^^^^^^^^^^^^^^^^^^^^^^^TEXT:  Ltd (#12324)^^^^^^^^^^^^^^^^^^^^^^^^
 *******************************************************************END OUTER LOOP 12:***********************************************************************


 *******************************************************************START OUTER LOOP 13:********************************************************************* 
(Inside TokenIterator::next()) The next token is: . (#13)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 2
     (Inside SpecTokenIterator::decode()) Skip forward for this iteration!
^^^^^^^^^^^^^^^^^^^^^^^^TEXT: . (#13)^^^^^^^^^^^^^^^^^^^^^^^^
 *******************************************************************END OUTER LOOP 13:***********************************************************************


 *******************************************************************START OUTER LOOP 14:********************************************************************* 
(Inside TokenIterator::next()) The next token is:  ( (#320)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 1
 (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is:  ( (#320)
            (Inside TokenTree::draft()) Start forwarding in draft model: time 1
            (Inside TokenTree::draft()) Start forwarding in draft model: time 2
            (Inside TokenTree::draft()) Start forwarding in draft model: time 3
            (Inside TokenTree::draft()) Start forwarding in draft model: time 4
            (Inside TokenTree::draft()) n_saved_tokens: 4; n_nodes: 18
      (Inside TokenTree::generate_tokens()) Start forwarding in target model (slow!)
            (Inside TokenTree::verify()) Generated token by target model: (#45)
            (Inside TokenTree::verify()) Accepted token by target model: (#45)
            (Inside TokenTree::verify()) Generated token by target model: (#3810)
            (Inside TokenTree::verify()) Accepted token by target model: (#3810)
            (Inside TokenTree::verify()) Generated token by target model: (#8)
            (Inside TokenTree::verify()) Accepted token by target model: (#8)
            (Inside TokenTree::verify()) Generated token by target model: (#374)
            (Inside TokenTree::verify()) Accepted token by target model: (#374)
            (Inside TokenTree::verify()) Generated token by target model: (#304)
            (Inside TokenTree::verify()) n_generate_tokens: 5; stat.n_generated_tokens: 19 
            (Inside TokenTree::verify()) n_accepted_tokens: 4; stat.n_accepted_tokens: 9 

========================================DEBUG TOKEN TREE START=========================================
[ACC] " (" 1.00
├── [ACC] "N" 0.54
│   └── [ACC] "IO" 0.91
│       ├── [ACC] ")" 0.52
│       │   └── [ACC] " is" 0.59
│       ├── [REJ] ")\n\n" 0.10
│       ├── [REJ] "CO" 0.10
│       ├── [REJ] ")," 0.09
│       ├── [REJ] ":" 0.05
│       ├── [REJ] "IO" 0.05
│       └── [REJ] "," 0.05
├── [REJ] "NYSE" 0.14
├── [REJ] "formerly" 0.11
├── [REJ] "NASDAQ" 0.06
├── [REJ] "here" 0.05
├── [REJ] "R" 0.04
├── [REJ] "NY" 0.04
└── [REJ] "NR" 0.03

========================================DEBUG TOKEN TREE END===========================================
     (Inside SpecTokenIterator::decode()) token queue:  N (#45),  IO (#3810),  ) (#8),   is (#374),   in (#304), 

^^^^^^^^^^^^^^^^^^^^^^^^TEXT:  ( (#320)^^^^^^^^^^^^^^^^^^^^^^^^
 *******************************************************************END OUTER LOOP 14:***********************************************************************


 *******************************************************************START OUTER LOOP 15:********************************************************************* 
(Inside TokenIterator::next()) The next token is: N (#45)
 (Inside SpecTokenIterator::decode()) m_tokens.size() == 5
     (Inside SpecTokenIterator::decode()) Skip forward for this iteration!
^^^^^^^^^^^^^^^^^^^^^^^^TEXT: N (#45)^^^^^^^^^^^^^^^^^^^^^^^^
 *******************************************************************END OUTER LOOP 15:***********************************************************************



[INFO ] prefill time: 12.948 s
[INFO ] prefill speed (6 tokens): 0.4633920296570899 tokens/s
[INFO ] decode speed (15 tokens): 0.041445394311481476 tokens/s
[INFO ] total speed: 0.05601942006562275 tokens/s
Speculative token tree statistics:
- 10 iterations, 19 generated tokens
- 1.900 tokens/iteration
- 3.900 draft-forwards/iteration
- Accept ratio: 5.696%
- Draft effective ratio: 23.077%

Process finished with exit code 0
```
