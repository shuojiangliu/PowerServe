# Example Debug Printings

Speculative decoding (`top_k = 2, draft_batch_size = 18`):

<pre>$ /project_root/bin/run --work-folder /project_root/models/ --model smallthinker-3b --draft-model smallthinker-0.5b --thread 4 --prompt &quot;Please introduce the company NIO.&quot; --no-qnn
[INFO ] Compiled on: Feb  5 2025 at 10:27:56
[INFO ] Load model qwen2 ...
[INFO ] Load model qwen2 ...
[INFO ] after model init: [Memory(MB)] VMS: 4122, RSS: 4118
[INFO ] after platform init: [Memory(MB)] VMS: 7195, RSS: 4118
[INFO ] after attn init: [Memory(MB)] VMS: 7195, RSS: 4118
[DEBUG] special_bos         : 151643: &lt;|endoftext|&gt;
[DEBUG] special_eos         : 151645: &lt;|im_end|&gt;
[DEBUG] special_pad         : 151643: &lt;|endoftext|&gt;
[DEBUG] special_eot         : 151645: &lt;|im_end|&gt;
[INFO ] after tokenizer init: [Memory(MB)] VMS: 7245, RSS: 4169
[INFO ] seed: 0
[INFO ] after sampler init: [Memory(MB)] VMS: 7245, RSS: 4169
[INFO ] prompt      : &quot;Please introduce the company NIO.&quot;
[INFO ] n_predicts  : 16
[INFO ] model arch  : qwen2
[INFO ] n_threads   : 4
[INFO ] batch_size   : 128
Please introduce the company NIO.
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
<font color="#A2734C"> *******************************************************************START OUTER LOOP 1:********************************************************************* </font>
<font color="#C01C28">(Inside TokenIterator::next()) The next token is: . (#13)</font>
<font color="#A347BA"> (Inside SpecTokenIterator::decode()) m_tokens.size() == 1</font>
<font color="#A347BA"> (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is: . (#13)</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 1</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 2</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 3</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 4</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 5</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 6</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 7</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 8</font>
<font color="#C01C28">            (Inside TokenTree::draft()) n_saved_tokens: 8; n_nodes: 17</font>
<font color="#C01C28">      (Inside TokenTree::generate_tokens()) Start forwarding in target model (slow!)</font>
<font color="#C01C28">            (Inside TokenTree::verify()) Generated token by target model: (#16209)</font>
<font color="#C01C28">            (Inside TokenTree::verify()) n_generate_tokens: 1; stat.n_generated_tokens: 1 </font>
<font color="#C01C28">            (Inside TokenTree::verify()) n_accepted_tokens: 0; stat.n_accepted_tokens: 0 </font>

<font color="#C01C28">========================================DEBUG TOKEN TREE START=========================================</font>
<font color="#12488B">[ACC] &quot;.&quot;(#13) 1.00</font>
<font color="#12488B">├── [REJ] &quot; N&quot;(#451) 0.84</font>
<font color="#12488B">│   ├── [REJ] &quot;IO&quot;(#3810) 0.99</font>
<font color="#12488B">│   │   ├── [REJ] &quot; is&quot;(#374) 0.88</font>
<font color="#12488B">│   │   │   ├── [REJ] &quot; a&quot;(#264) 0.84</font>
<font color="#12488B">│   │   │   │   ├── [REJ] &quot; leading&quot;(#6388) 0.73</font>
<font color="#12488B">│   │   │   │   │   ├── [REJ] &quot; provider&quot;(#9109) 0.54</font>
<font color="#12488B">│   │   │   │   │   │   ├── [REJ] &quot; of&quot;(#315) 0.98</font>
<font color="#12488B">│   │   │   │   │   │   │   ├── [REJ] &quot; innovative&quot;(#18199) 0.68</font>
<font color="#12488B">│   │   │   │   │   │   │   └── [REJ] &quot; high&quot;(#1550) 0.32</font>
<font color="#12488B">│   │   │   │   │   │   └── [REJ] &quot; in&quot;(#304) 0.02</font>
<font color="#12488B">│   │   │   │   │   └── [REJ] &quot; technology&quot;(#5440) 0.46</font>
<font color="#12488B">│   │   │   │   └── [REJ] &quot; company&quot;(#2813) 0.27</font>
<font color="#12488B">│   │   │   └── [REJ] &quot; an&quot;(#458) 0.16</font>
<font color="#12488B">│   │   └── [REJ] &quot;,&quot;(#11) 0.12</font>
<font color="#12488B">│   └── [REJ] &quot;io&quot;(#815) 0.01</font>
<font color="#12488B">└── [REJ] &quot; I&quot;(#358) 0.16</font>

<font color="#C01C28">========================================DEBUG TOKEN TREE END===========================================</font>
<font color="#A347BA">     (Inside SpecTokenIterator::decode()) token queue:   Resources (#16209), </font>
<font color="#A2734C"> *******************************************************************EARLY END OUTER LOOP 1:************************************************************* </font>


<font color="#A2734C"> *******************************************************************START OUTER LOOP 2:********************************************************************* </font>
<font color="#C01C28">(Inside TokenIterator::next()) The next token is:  Resources (#16209)</font>
<font color="#A347BA"> (Inside SpecTokenIterator::decode()) m_tokens.size() == 1</font>
<font color="#A347BA"> (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is:  Resources (#16209)</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 1</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 2</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 3</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 4</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 5</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 6</font>
<font color="#C01C28">            (Inside TokenTree::draft()) n_saved_tokens: 6; n_nodes: 13</font>
<font color="#C01C28">      (Inside TokenTree::generate_tokens()) Start forwarding in target model (slow!)</font>
<font color="#C01C28">            (Inside TokenTree::verify()) Generated token by target model: (#16209)</font>
<font color="#C01C28">            (Inside TokenTree::verify()) n_generate_tokens: 1; stat.n_generated_tokens: 2 </font>
<font color="#C01C28">            (Inside TokenTree::verify()) n_accepted_tokens: 0; stat.n_accepted_tokens: 0 </font>

<font color="#C01C28">========================================DEBUG TOKEN TREE START=========================================</font>
<font color="#12488B">[ACC] &quot; Resources&quot;(#16209) 1.00</font>
<font color="#12488B">├── [REJ] &quot;:&quot;(#25) 0.67</font>
<font color="#12488B">│   ├── [REJ] &quot; N&quot;(#451) 0.71</font>
<font color="#12488B">│   │   ├── [REJ] &quot;IO&quot;(#3810) 0.99</font>
<font color="#12488B">│   │   │   ├── [REJ] &quot; is&quot;(#374) 0.70</font>
<font color="#12488B">│   │   │   │   ├── [REJ] &quot; a&quot;(#264) 0.87</font>
<font color="#12488B">│   │   │   │   │   ├── [REJ] &quot; leading&quot;(#6388) 0.64</font>
<font color="#12488B">│   │   │   │   │   └── [REJ] &quot; company&quot;(#2813) 0.36</font>
<font color="#12488B">│   │   │   │   └── [REJ] &quot; an&quot;(#458) 0.13</font>
<font color="#12488B">│   │   │   └── [REJ] &quot; has&quot;(#702) 0.30</font>
<font color="#12488B">│   │   └── [REJ] &quot;io&quot;(#815) 0.01</font>
<font color="#12488B">│   └── [REJ] &quot; https&quot;(#3703) 0.29</font>
<font color="#12488B">└── [REJ] &quot;:\n\n&quot;(#1447) 0.33</font>

<font color="#C01C28">========================================DEBUG TOKEN TREE END===========================================</font>
<font color="#A347BA">     (Inside SpecTokenIterator::decode()) token queue:   Resources (#16209), </font>

<font color="#26A269">^^^^^^^^^^^^^^^^^^^^^^^^TEXT:  Resources (#16209)^^^^^^^^^^^^^^^^^^^^^^^^</font>
<font color="#A2734C"> *******************************************************************END OUTER LOOP 2:***********************************************************************</font>


<font color="#A2734C"> *******************************************************************START OUTER LOOP 3:********************************************************************* </font>
<font color="#C01C28">(Inside TokenIterator::next()) The next token is:  Resources (#16209)</font>
<font color="#A347BA"> (Inside SpecTokenIterator::decode()) m_tokens.size() == 1</font>
<font color="#A347BA"> (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is:  Resources (#16209)</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 1</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 2</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 3</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 4</font>
<font color="#C01C28">            (Inside TokenTree::draft()) n_saved_tokens: 4; n_nodes: 9</font>
<font color="#C01C28">      (Inside TokenTree::generate_tokens()) Start forwarding in target model (slow!)</font>
<font color="#C01C28">            (Inside TokenTree::verify()) Generated token by target model: (#16209)</font>
<font color="#C01C28">            (Inside TokenTree::verify()) n_generate_tokens: 1; stat.n_generated_tokens: 3 </font>
<font color="#C01C28">            (Inside TokenTree::verify()) n_accepted_tokens: 0; stat.n_accepted_tokens: 0 </font>

<font color="#C01C28">========================================DEBUG TOKEN TREE START=========================================</font>
<font color="#12488B">[ACC] &quot; Resources&quot;(#16209) 1.00</font>
<font color="#12488B">├── [REJ] &quot; are&quot;(#525) 0.54</font>
<font color="#12488B">│   ├── [REJ] &quot; a&quot;(#264) 0.65</font>
<font color="#12488B">│   │   ├── [REJ] &quot; leading&quot;(#6388) 0.68</font>
<font color="#12488B">│   │   │   ├── [REJ] &quot; provider&quot;(#9109) 0.70</font>
<font color="#12488B">│   │   │   └── [REJ] &quot; technology&quot;(#5440) 0.30</font>
<font color="#12488B">│   │   └── [REJ] &quot; company&quot;(#2813) 0.32</font>
<font color="#12488B">│   └── [REJ] &quot; the&quot;(#279) 0.35</font>
<font color="#12488B">└── [REJ] &quot; N&quot;(#451) 0.46</font>

<font color="#C01C28">========================================DEBUG TOKEN TREE END===========================================</font>
<font color="#A347BA">     (Inside SpecTokenIterator::decode()) token queue:   Resources (#16209), </font>

<font color="#26A269">^^^^^^^^^^^^^^^^^^^^^^^^TEXT:  Resources (#16209)^^^^^^^^^^^^^^^^^^^^^^^^</font>
<font color="#A2734C"> *******************************************************************END OUTER LOOP 3:***********************************************************************</font>


<font color="#A2734C"> *******************************************************************START OUTER LOOP 4:********************************************************************* </font>
<font color="#C01C28">(Inside TokenIterator::next()) The next token is:  Resources (#16209)</font>
<font color="#A347BA"> (Inside SpecTokenIterator::decode()) m_tokens.size() == 1</font>
<font color="#A347BA"> (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is:  Resources (#16209)</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 1</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 2</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 3</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 4</font>
<font color="#C01C28">            (Inside TokenTree::draft()) n_saved_tokens: 4; n_nodes: 9</font>
<font color="#C01C28">      (Inside TokenTree::generate_tokens()) Start forwarding in target model (slow!)</font>
<font color="#C01C28">            (Inside TokenTree::verify()) Generated token by target model: (#16209)</font>
<font color="#C01C28">            (Inside TokenTree::verify()) Accepted token by target model: (#16209)</font>
<font color="#C01C28">            (Inside TokenTree::verify()) Generated token by target model: (#16209)</font>
<font color="#C01C28">            (Inside TokenTree::verify()) Accepted token by target model: (#16209)</font>
<font color="#C01C28">            (Inside TokenTree::verify()) Generated token by target model: (#16209)</font>
<font color="#C01C28">            (Inside TokenTree::verify()) Accepted token by target model: (#16209)</font>
<font color="#C01C28">            (Inside TokenTree::verify()) Generated token by target model: (#16209)</font>
<font color="#C01C28">            (Inside TokenTree::verify()) Accepted token by target model: (#16209)</font>
<font color="#C01C28">            (Inside TokenTree::verify()) Generated token by target model: (#16209)</font>
<font color="#C01C28">            (Inside TokenTree::verify()) n_generate_tokens: 5; stat.n_generated_tokens: 8 </font>
<font color="#C01C28">            (Inside TokenTree::verify()) n_accepted_tokens: 4; stat.n_accepted_tokens: 4 </font>

<font color="#C01C28">========================================DEBUG TOKEN TREE START=========================================</font>
<font color="#12488B">[ACC] &quot; Resources&quot;(#16209) 1.00</font>
<font color="#12488B">├── [ACC] &quot; Resources&quot;(#16209) 0.53</font>
<font color="#12488B">│   ├── [ACC] &quot; Resources&quot;(#16209) 0.64</font>
<font color="#12488B">│   │   ├── [ACC] &quot; Resources&quot;(#16209) 0.71</font>
<font color="#12488B">│   │   │   ├── [ACC] &quot; Resources&quot;(#16209) 0.83</font>
<font color="#12488B">│   │   │   └── [REJ] &quot;\n\n&quot;(#271) 0.17</font>
<font color="#12488B">│   │   └── [REJ] &quot;\n\n&quot;(#271) 0.29</font>
<font color="#12488B">│   └── [REJ] &quot;\n\n&quot;(#271) 0.36</font>
<font color="#12488B">└── [REJ] &quot;\n\n&quot;(#271) 0.47</font>

<font color="#C01C28">========================================DEBUG TOKEN TREE END===========================================</font>
<font color="#A347BA">     (Inside SpecTokenIterator::decode()) token queue:   Resources (#16209),   Resources (#16209),   Resources (#16209),   Resources (#16209),   Resources (#16209), </font>

<font color="#26A269">^^^^^^^^^^^^^^^^^^^^^^^^TEXT:  Resources (#16209)^^^^^^^^^^^^^^^^^^^^^^^^</font>
<font color="#A2734C"> *******************************************************************END OUTER LOOP 4:***********************************************************************</font>


<font color="#A2734C"> *******************************************************************START OUTER LOOP 5:********************************************************************* </font>
<font color="#C01C28">(Inside TokenIterator::next()) The next token is:  Resources (#16209)</font>
<font color="#A347BA"> (Inside SpecTokenIterator::decode()) m_tokens.size() == 5</font>
<font color="#A347BA">     (Inside SpecTokenIterator::decode()) Skip forward for this iteration!</font>
<font color="#26A269">^^^^^^^^^^^^^^^^^^^^^^^^TEXT:  Resources (#16209)^^^^^^^^^^^^^^^^^^^^^^^^</font>
<font color="#A2734C"> *******************************************************************END OUTER LOOP 5:***********************************************************************</font>


<font color="#A2734C"> *******************************************************************START OUTER LOOP 6:********************************************************************* </font>
<font color="#C01C28">(Inside TokenIterator::next()) The next token is:  Resources (#16209)</font>
<font color="#A347BA"> (Inside SpecTokenIterator::decode()) m_tokens.size() == 4</font>
<font color="#A347BA">     (Inside SpecTokenIterator::decode()) Skip forward for this iteration!</font>
<font color="#26A269">^^^^^^^^^^^^^^^^^^^^^^^^TEXT:  Resources (#16209)^^^^^^^^^^^^^^^^^^^^^^^^</font>
<font color="#A2734C"> *******************************************************************END OUTER LOOP 6:***********************************************************************</font>


<font color="#A2734C"> *******************************************************************START OUTER LOOP 7:********************************************************************* </font>
<font color="#C01C28">(Inside TokenIterator::next()) The next token is:  Resources (#16209)</font>
<font color="#A347BA"> (Inside SpecTokenIterator::decode()) m_tokens.size() == 3</font>
<font color="#A347BA">     (Inside SpecTokenIterator::decode()) Skip forward for this iteration!</font>
<font color="#26A269">^^^^^^^^^^^^^^^^^^^^^^^^TEXT:  Resources (#16209)^^^^^^^^^^^^^^^^^^^^^^^^</font>
<font color="#A2734C"> *******************************************************************END OUTER LOOP 7:***********************************************************************</font>


<font color="#A2734C"> *******************************************************************START OUTER LOOP 8:********************************************************************* </font>
<font color="#C01C28">(Inside TokenIterator::next()) The next token is:  Resources (#16209)</font>
<font color="#A347BA"> (Inside SpecTokenIterator::decode()) m_tokens.size() == 2</font>
<font color="#A347BA">     (Inside SpecTokenIterator::decode()) Skip forward for this iteration!</font>
<font color="#26A269">^^^^^^^^^^^^^^^^^^^^^^^^TEXT:  Resources (#16209)^^^^^^^^^^^^^^^^^^^^^^^^</font>
<font color="#A2734C"> *******************************************************************END OUTER LOOP 8:***********************************************************************</font>


<font color="#A2734C"> *******************************************************************START OUTER LOOP 9:********************************************************************* </font>
<font color="#C01C28">(Inside TokenIterator::next()) The next token is:  Resources (#16209)</font>
<font color="#A347BA"> (Inside SpecTokenIterator::decode()) m_tokens.size() == 1</font>
<font color="#A347BA"> (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is:  Resources (#16209)</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 1</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 2</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 3</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 4</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 5</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 6</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 7</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 8</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 9</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 10</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 11</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 12</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 13</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 14</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 15</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 16</font>
<font color="#C01C28">            (Inside TokenTree::draft()) n_saved_tokens: 16; n_nodes: 18</font>
<font color="#C01C28">      (Inside TokenTree::generate_tokens()) Start forwarding in target model (slow!)</font>
<font color="#C01C28">            (Inside TokenTree::verify()) Generated token by target model: (#3539)</font>
<font color="#C01C28">            (Inside TokenTree::verify()) n_generate_tokens: 1; stat.n_generated_tokens: 9 </font>
<font color="#C01C28">            (Inside TokenTree::verify()) n_accepted_tokens: 0; stat.n_accepted_tokens: 4 </font>

<font color="#C01C28">========================================DEBUG TOKEN TREE START=========================================</font>
<font color="#12488B">[ACC] &quot; Resources&quot;(#16209) 1.00</font>
<font color="#12488B">└── [REJ] &quot; Resources&quot;(#16209) 0.90</font>
<font color="#12488B">    ├── [REJ] &quot; Resources&quot;(#16209) 0.86</font>
<font color="#12488B">    │   └── [REJ] &quot; Resources&quot;(#16209) 0.84</font>
<font color="#12488B">    │       └── [REJ] &quot; Resources&quot;(#16209) 0.85</font>
<font color="#12488B">    │           └── [REJ] &quot; Resources&quot;(#16209) 0.87</font>
<font color="#12488B">    │               └── [REJ] &quot; Resources&quot;(#16209) 0.91</font>
<font color="#12488B">    │                   └── [REJ] &quot; Resources&quot;(#16209) 0.91</font>
<font color="#12488B">    │                       └── [REJ] &quot; Resources&quot;(#16209) 0.91</font>
<font color="#12488B">    │                           └── [REJ] &quot; Resources&quot;(#16209) 0.92</font>
<font color="#12488B">    │                               └── [REJ] &quot; Resources&quot;(#16209) 0.92</font>
<font color="#12488B">    │                                   └── [REJ] &quot; Resources&quot;(#16209) 0.93</font>
<font color="#12488B">    │                                       └── [REJ] &quot; Resources&quot;(#16209) 0.93</font>
<font color="#12488B">    │                                           └── [REJ] &quot; Resources&quot;(#16209) 0.93</font>
<font color="#12488B">    │                                               └── [REJ] &quot; Resources&quot;(#16209) 0.93</font>
<font color="#12488B">    │                                                   └── [REJ] &quot; Resources&quot;(#16209) 0.92</font>
<font color="#12488B">    │                                                       └── [REJ] &quot; Resources&quot;(#16209) 0.93</font>
<font color="#12488B">    └── [REJ] &quot;\n\n&quot;(#271) 0.14</font>

<font color="#C01C28">========================================DEBUG TOKEN TREE END===========================================</font>
<font color="#A347BA">     (Inside SpecTokenIterator::decode()) token queue:   Co (#3539), </font>

<font color="#26A269">^^^^^^^^^^^^^^^^^^^^^^^^TEXT:  Resources (#16209)^^^^^^^^^^^^^^^^^^^^^^^^</font>
<font color="#A2734C"> *******************************************************************END OUTER LOOP 9:***********************************************************************</font>


<font color="#A2734C"> *******************************************************************START OUTER LOOP 10:********************************************************************* </font>
<font color="#C01C28">(Inside TokenIterator::next()) The next token is:  Co (#3539)</font>
<font color="#A347BA"> (Inside SpecTokenIterator::decode()) m_tokens.size() == 1</font>
<font color="#A347BA"> (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is:  Co (#3539)</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 1</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 2</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 3</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 4</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 5</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 6</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 7</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 8</font>
<font color="#C01C28">            (Inside TokenTree::draft()) n_saved_tokens: 8; n_nodes: 17</font>
<font color="#C01C28">      (Inside TokenTree::generate_tokens()) Start forwarding in target model (slow!)</font>
<font color="#C01C28">            (Inside TokenTree::verify()) Generated token by target model: (#16209)</font>
<font color="#C01C28">            (Inside TokenTree::verify()) n_generate_tokens: 1; stat.n_generated_tokens: 10 </font>
<font color="#C01C28">            (Inside TokenTree::verify()) n_accepted_tokens: 0; stat.n_accepted_tokens: 4 </font>

<font color="#C01C28">========================================DEBUG TOKEN TREE START=========================================</font>
<font color="#12488B">[ACC] &quot; Co&quot;(#3539) 1.00</font>
<font color="#12488B">├── [REJ] &quot;.&quot;(#13) 0.76</font>
<font color="#12488B">│   ├── [REJ] &quot; N&quot;(#451) 0.51</font>
<font color="#12488B">│   │   ├── [REJ] &quot;IO&quot;(#3810) 0.97</font>
<font color="#12488B">│   │   │   ├── [REJ] &quot; is&quot;(#374) 0.66</font>
<font color="#12488B">│   │   │   │   ├── [REJ] &quot; for&quot;(#369) 0.69</font>
<font color="#12488B">│   │   │   │   └── [REJ] &quot; the&quot;(#279) 0.31</font>
<font color="#12488B">│   │   │   └── [REJ] &quot;,&quot;(#11) 0.34</font>
<font color="#12488B">│   │   └── [REJ] &quot;io&quot;(#815) 0.03</font>
<font color="#12488B">│   └── [REJ] &quot; (&quot;(#320) 0.49</font>
<font color="#12488B">│       ├── [REJ] &quot;N&quot;(#45) 0.81</font>
<font color="#12488B">│       │   ├── [REJ] &quot;IO&quot;(#3810) 0.84</font>
<font color="#12488B">│       │   │   ├── [REJ] &quot;)&quot;(#8) 0.76</font>
<font color="#12488B">│       │   │   └── [REJ] &quot;),&quot;(#701) 0.24</font>
<font color="#12488B">│       │   └── [REJ] &quot;OR&quot;(#868) 0.16</font>
<font color="#12488B">│       └── [REJ] &quot;formerly&quot;(#69514) 0.19</font>
<font color="#12488B">└── [REJ] &quot; Ltd&quot;(#12324) 0.24</font>

<font color="#C01C28">========================================DEBUG TOKEN TREE END===========================================</font>
<font color="#A347BA">     (Inside SpecTokenIterator::decode()) token queue:   Resources (#16209), </font>

<font color="#26A269">^^^^^^^^^^^^^^^^^^^^^^^^TEXT:  Co (#3539)^^^^^^^^^^^^^^^^^^^^^^^^</font>
<font color="#A2734C"> *******************************************************************END OUTER LOOP 10:***********************************************************************</font>


<font color="#A2734C"> *******************************************************************START OUTER LOOP 11:********************************************************************* </font>
<font color="#C01C28">(Inside TokenIterator::next()) The next token is:  Resources (#16209)</font>
<font color="#A347BA"> (Inside SpecTokenIterator::decode()) m_tokens.size() == 1</font>
<font color="#A347BA"> (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is:  Resources (#16209)</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 1</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 2</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 3</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 4</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 5</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 6</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 7</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 8</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 9</font>
<font color="#C01C28">            (Inside TokenTree::draft()) n_saved_tokens: 9; n_nodes: 18</font>
<font color="#C01C28">      (Inside TokenTree::generate_tokens()) Start forwarding in target model (slow!)</font>
<font color="#C01C28">            (Inside TokenTree::verify()) Generated token by target model: (#3539)</font>
<font color="#C01C28">            (Inside TokenTree::verify()) Accepted token by target model: (#3539)</font>
<font color="#C01C28">            (Inside TokenTree::verify()) Generated token by target model: (#271)</font>
<font color="#C01C28">            (Inside TokenTree::verify()) n_generate_tokens: 2; stat.n_generated_tokens: 12 </font>
<font color="#C01C28">            (Inside TokenTree::verify()) n_accepted_tokens: 1; stat.n_accepted_tokens: 5 </font>

<font color="#C01C28">========================================DEBUG TOKEN TREE START=========================================</font>
<font color="#12488B">[ACC] &quot; Resources&quot;(#16209) 1.00</font>
<font color="#12488B">├── [REJ] &quot; Resources&quot;(#16209) 0.81</font>
<font color="#12488B">│   ├── [REJ] &quot; Resources&quot;(#16209) 0.87</font>
<font color="#12488B">│   │   ├── [REJ] &quot; Resources&quot;(#16209) 0.92</font>
<font color="#12488B">│   │   │   └── [REJ] &quot; Resources&quot;(#16209) 0.92</font>
<font color="#12488B">│   │   │       ├── [REJ] &quot; Resources&quot;(#16209) 0.91</font>
<font color="#12488B">│   │   │       │   ├── [REJ] &quot; Resources&quot;(#16209) 0.86</font>
<font color="#12488B">│   │   │       │   │   ├── [REJ] &quot; Resources&quot;(#16209) 0.87</font>
<font color="#12488B">│   │   │       │   │   │   ├── [REJ] &quot; Resources&quot;(#16209) 0.64</font>
<font color="#12488B">│   │   │       │   │   │   │   ├── [REJ] &quot; Resources&quot;(#16209) 0.64</font>
<font color="#12488B">│   │   │       │   │   │   │   └── [REJ] &quot; Co&quot;(#3539) 0.36</font>
<font color="#12488B">│   │   │       │   │   │   └── [REJ] &quot; Co&quot;(#3539) 0.36</font>
<font color="#12488B">│   │   │       │   │   └── [REJ] &quot;\n\n&quot;(#271) 0.13</font>
<font color="#12488B">│   │   │       │   └── [REJ] &quot;\n\n&quot;(#271) 0.14</font>
<font color="#12488B">│   │   │       └── [REJ] &quot;\n\n&quot;(#271) 0.09</font>
<font color="#12488B">│   │   └── [REJ] &quot;\n\n&quot;(#271) 0.08</font>
<font color="#12488B">│   └── [REJ] &quot; Co&quot;(#3539) 0.13</font>
<font color="#12488B">└── [ACC] &quot; Co&quot;(#3539) 0.19</font>

<font color="#C01C28">========================================DEBUG TOKEN TREE END===========================================</font>
<font color="#A347BA">     (Inside SpecTokenIterator::decode()) token queue:   Co (#3539),  </font>

<font color="#A347BA"> (#271), </font>

<font color="#26A269">^^^^^^^^^^^^^^^^^^^^^^^^TEXT:  Resources (#16209)^^^^^^^^^^^^^^^^^^^^^^^^</font>
<font color="#A2734C"> *******************************************************************END OUTER LOOP 11:***********************************************************************</font>


<font color="#A2734C"> *******************************************************************START OUTER LOOP 12:********************************************************************* </font>
<font color="#C01C28">(Inside TokenIterator::next()) The next token is:  Co (#3539)</font>
<font color="#A347BA"> (Inside SpecTokenIterator::decode()) m_tokens.size() == 2</font>
<font color="#A347BA">     (Inside SpecTokenIterator::decode()) Skip forward for this iteration!</font>
<font color="#26A269">^^^^^^^^^^^^^^^^^^^^^^^^TEXT:  Co (#3539)^^^^^^^^^^^^^^^^^^^^^^^^</font>
<font color="#A2734C"> *******************************************************************END OUTER LOOP 12:***********************************************************************</font>


<font color="#A2734C"> *******************************************************************START OUTER LOOP 13:********************************************************************* </font>
<font color="#C01C28">(Inside TokenIterator::next()) The next token is: </font>

<font color="#C01C28"> (#271)</font>
<font color="#A347BA"> (Inside SpecTokenIterator::decode()) m_tokens.size() == 1</font>
<font color="#A347BA"> (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is: </font>

<font color="#A347BA"> (#271)</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 1</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 2</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 3</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 4</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 5</font>
<font color="#C01C28">            (Inside TokenTree::draft()) n_saved_tokens: 5; n_nodes: 11</font>
<font color="#C01C28">      (Inside TokenTree::generate_tokens()) Start forwarding in target model (slow!)</font>
<font color="#C01C28">            (Inside TokenTree::verify()) Generated token by target model: (#16209)</font>
<font color="#C01C28">            (Inside TokenTree::verify()) n_generate_tokens: 1; stat.n_generated_tokens: 13 </font>
<font color="#C01C28">            (Inside TokenTree::verify()) n_accepted_tokens: 0; stat.n_accepted_tokens: 5 </font>

<font color="#C01C28">========================================DEBUG TOKEN TREE START=========================================</font>
<font color="#12488B">[ACC] &quot;\n\n&quot;(#271) 1.00</font>
<font color="#12488B">├── [REJ] &quot;N&quot;(#45) 0.60</font>
<font color="#12488B">│   ├── [REJ] &quot;IO&quot;(#3810) 0.99</font>
<font color="#12488B">│   │   ├── [REJ] &quot; is&quot;(#374) 0.67</font>
<font color="#12488B">│   │   │   ├── [REJ] &quot; a&quot;(#264) 0.85</font>
<font color="#12488B">│   │   │   │   ├── [REJ] &quot; leading&quot;(#6388) 0.57</font>
<font color="#12488B">│   │   │   │   └── [REJ] &quot; company&quot;(#2813) 0.43</font>
<font color="#12488B">│   │   │   └── [REJ] &quot; an&quot;(#458) 0.15</font>
<font color="#12488B">│   │   └── [REJ] &quot;,&quot;(#11) 0.33</font>
<font color="#12488B">│   └── [REJ] &quot;io&quot;(#815) 0.01</font>
<font color="#12488B">└── [REJ] &quot;I&quot;(#40) 0.40</font>

<font color="#C01C28">========================================DEBUG TOKEN TREE END===========================================</font>
<font color="#A347BA">     (Inside SpecTokenIterator::decode()) token queue:   Resources (#16209), </font>

<font color="#26A269">^^^^^^^^^^^^^^^^^^^^^^^^TEXT: </font>

<font color="#26A269"> (#271)^^^^^^^^^^^^^^^^^^^^^^^^</font>
<font color="#A2734C"> *******************************************************************END OUTER LOOP 13:***********************************************************************</font>


<font color="#A2734C"> *******************************************************************START OUTER LOOP 14:********************************************************************* </font>
<font color="#C01C28">(Inside TokenIterator::next()) The next token is:  Resources (#16209)</font>
<font color="#A347BA"> (Inside SpecTokenIterator::decode()) m_tokens.size() == 1</font>
<font color="#A347BA"> (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is:  Resources (#16209)</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 1</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 2</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 3</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 4</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 5</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 6</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 7</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 8</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 9</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 10</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 11</font>
<font color="#C01C28">            (Inside TokenTree::draft()) n_saved_tokens: 11; n_nodes: 18</font>
<font color="#C01C28">      (Inside TokenTree::generate_tokens()) Start forwarding in target model (slow!)</font>
<font color="#C01C28">            (Inside TokenTree::verify()) Generated token by target model: (#3539)</font>
<font color="#C01C28">            (Inside TokenTree::verify()) Accepted token by target model: (#3539)</font>
<font color="#C01C28">            (Inside TokenTree::verify()) Generated token by target model: (#271)</font>
<font color="#C01C28">            (Inside TokenTree::verify()) n_generate_tokens: 2; stat.n_generated_tokens: 15 </font>
<font color="#C01C28">            (Inside TokenTree::verify()) n_accepted_tokens: 1; stat.n_accepted_tokens: 6 </font>

<font color="#C01C28">========================================DEBUG TOKEN TREE START=========================================</font>
<font color="#12488B">[ACC] &quot; Resources&quot;(#16209) 1.00</font>
<font color="#12488B">├── [REJ] &quot; Resources&quot;(#16209) 0.81</font>
<font color="#12488B">│   ├── [REJ] &quot; Resources&quot;(#16209) 0.94</font>
<font color="#12488B">│   │   └── [REJ] &quot; Resources&quot;(#16209) 0.96</font>
<font color="#12488B">│   │       └── [REJ] &quot; Resources&quot;(#16209) 0.98</font>
<font color="#12488B">│   │           └── [REJ] &quot; Resources&quot;(#16209) 0.97</font>
<font color="#12488B">│   │               └── [REJ] &quot; Resources&quot;(#16209) 0.97</font>
<font color="#12488B">│   │                   ├── [REJ] &quot; Resources&quot;(#16209) 0.95</font>
<font color="#12488B">│   │                   │   ├── [REJ] &quot; Resources&quot;(#16209) 0.67</font>
<font color="#12488B">│   │                   │   │   ├── [REJ] &quot; Resources&quot;(#16209) 0.58</font>
<font color="#12488B">│   │                   │   │   │   ├── [REJ] &quot; Resources&quot;(#16209) 0.82</font>
<font color="#12488B">│   │                   │   │   │   │   └── [REJ] &quot; Resources&quot;(#16209) 0.86</font>
<font color="#12488B">│   │                   │   │   │   └── [REJ] &quot; Co&quot;(#3539) 0.18</font>
<font color="#12488B">│   │                   │   │   └── [REJ] &quot; Co&quot;(#3539) 0.42</font>
<font color="#12488B">│   │                   │   └── [REJ] &quot; Co&quot;(#3539) 0.33</font>
<font color="#12488B">│   │                   └── [REJ] &quot; Co&quot;(#3539) 0.05</font>
<font color="#12488B">│   └── [REJ] &quot; Co&quot;(#3539) 0.06</font>
<font color="#12488B">└── [ACC] &quot; Co&quot;(#3539) 0.19</font>

<font color="#C01C28">========================================DEBUG TOKEN TREE END===========================================</font>
<font color="#A347BA">     (Inside SpecTokenIterator::decode()) token queue:   Co (#3539),  </font>

<font color="#A347BA"> (#271), </font>

<font color="#26A269">^^^^^^^^^^^^^^^^^^^^^^^^TEXT:  Resources (#16209)^^^^^^^^^^^^^^^^^^^^^^^^</font>
<font color="#A2734C"> *******************************************************************END OUTER LOOP 14:***********************************************************************</font>


<font color="#A2734C"> *******************************************************************START OUTER LOOP 15:********************************************************************* </font>
<font color="#C01C28">(Inside TokenIterator::next()) The next token is:  Co (#3539)</font>
<font color="#A347BA"> (Inside SpecTokenIterator::decode()) m_tokens.size() == 2</font>
<font color="#A347BA">     (Inside SpecTokenIterator::decode()) Skip forward for this iteration!</font>
<font color="#26A269">^^^^^^^^^^^^^^^^^^^^^^^^TEXT:  Co (#3539)^^^^^^^^^^^^^^^^^^^^^^^^</font>
<font color="#A2734C"> *******************************************************************END OUTER LOOP 15:***********************************************************************</font>


<font color="#A2734C"> *******************************************************************START OUTER LOOP 16:********************************************************************* </font>
<font color="#C01C28">(Inside TokenIterator::next()) The next token is: </font>

<font color="#C01C28"> (#271)</font>
<font color="#A347BA"> (Inside SpecTokenIterator::decode()) m_tokens.size() == 1</font>
<font color="#A347BA"> (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is: </font>

<font color="#A347BA"> (#271)</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 1</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 2</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 3</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 4</font>
<font color="#C01C28">            (Inside TokenTree::draft()) Start forwarding in draft model: time 5</font>
<font color="#C01C28">            (Inside TokenTree::draft()) n_saved_tokens: 5; n_nodes: 11</font>
<font color="#C01C28">      (Inside TokenTree::generate_tokens()) Start forwarding in target model (slow!)</font>
<font color="#C01C28">            (Inside TokenTree::verify()) Generated token by target model: (#16209)</font>
<font color="#C01C28">            (Inside TokenTree::verify()) n_generate_tokens: 1; stat.n_generated_tokens: 16 </font>
<font color="#C01C28">            (Inside TokenTree::verify()) n_accepted_tokens: 0; stat.n_accepted_tokens: 6 </font>

<font color="#C01C28">========================================DEBUG TOKEN TREE START=========================================</font>
<font color="#12488B">[ACC] &quot;\n\n&quot;(#271) 1.00</font>
<font color="#12488B">├── [REJ] &quot;N&quot;(#45) 0.57</font>
<font color="#12488B">│   ├── [REJ] &quot;IO&quot;(#3810) 0.99</font>
<font color="#12488B">│   │   ├── [REJ] &quot; is&quot;(#374) 0.69</font>
<font color="#12488B">│   │   │   ├── [REJ] &quot; a&quot;(#264) 0.87</font>
<font color="#12488B">│   │   │   │   ├── [REJ] &quot; leading&quot;(#6388) 0.60</font>
<font color="#12488B">│   │   │   │   └── [REJ] &quot; company&quot;(#2813) 0.40</font>
<font color="#12488B">│   │   │   └── [REJ] &quot; an&quot;(#458) 0.13</font>
<font color="#12488B">│   │   └── [REJ] &quot;,&quot;(#11) 0.31</font>
<font color="#12488B">│   └── [REJ] &quot;io&quot;(#815) 0.01</font>
<font color="#12488B">└── [REJ] &quot; N&quot;(#451) 0.43</font>

<font color="#C01C28">========================================DEBUG TOKEN TREE END===========================================</font>
<font color="#A347BA">     (Inside SpecTokenIterator::decode()) token queue:   Resources (#16209), </font>

<font color="#26A269">^^^^^^^^^^^^^^^^^^^^^^^^TEXT: </font>

<font color="#26A269"> (#271)^^^^^^^^^^^^^^^^^^^^^^^^</font>
<font color="#A2734C"> *******************************************************************END OUTER LOOP 16:***********************************************************************</font>



<font color="#26A269">Final Output: </font>
<font color="#26A269"> Resources Resources Resources Resources Resources Resources Resources Resources Co Resources Co</font>

<font color="#26A269"> Resources Co</font>


[INFO ] prefill time: 16.961 s
[INFO ] prefill speed (6 tokens): 0.3537527268439361 tokens/s
[INFO ] decode speed (15 tokens): 0.030405734116044497 tokens/s
[INFO ] total speed: 0.04115315046963583 tokens/s
Speculative token tree statistics:
- 10 iterations, 16 generated tokens
- 1.600 tokens/iteration
- 7.600 draft-forwards/iteration
- Accept ratio: 4.580%
- Draft effective ratio: 7.895%
</pre>
