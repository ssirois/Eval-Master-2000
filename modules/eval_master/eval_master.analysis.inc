<?php

// TODO: Modify original file's hook_menu to create a callback to this form

function eval_master_analysis_form() {
  $form = array();

  $questions = _eval_master_get_questions();

  // Create an array of themed questions
  while ($question = db_fetch_array($questions)) {
    if ($question['type'] == 'multiple_choice') { // If question is a multiple choice question
      $raw_answers = _eval_master_analysis_get_answers($question);

      $average = _eval_master_analysis_get_average($answers);

      $clean_answers = array($average);
    }
    else { // Otherwise, it is a long answer question
      $clean_answers = _eval_master_analysis_get_answers($question, 10);
    }
  
    // Use builtin theme function to get unordered list from $clean_answers,
    // using question text as the list's title
    $themed_question = theme('item_list', $clean_answers, $question['title']);

    $raw_questions_list[] = $themed_question;
  }
  
  // Use builtin theme function to get ordered list from $questions_list
  $themed_questions_list = theme('item_list', $raw_questions_list, 'analysis', 'ol');

  $form['questions'] = array(
    '#value' => $themed_questions_list,
  );

  return $form;
}

/**
 * Returns all the answers of $question
 *
 * @param $question
 *   The question for which to get the answers
 * @param $limit
 *   The maximum number of answers to return
 * @return an array containing only the answers
 */
function _eval_master_analysis_get_answers($question, $limit = 200){
  $sql = 'SELECT * FROM {eval_master_answer} WHERE question_id = %d LIMIT %d';
  $sql_result = db_query($sql, $question, $limit);
  $survey_results = array();
  
  while($row = db_fetch_array($sql_results)) {
    $survey_results[] = $row['value'];
  }
 
  return $survey_results; 
}

/**
 * Takes an array of answers (of integer or string format) and
 * returns the average
 *
 * @param $answers
 *   The array of answers
 * @return integer value representing the average of all the values in $answers
 */
function _eval_master_analysis_get_average($answers){
  $total = 0;
  foreach($answers as $answer) {
    $total += $answer;
  }
  return $total / count($answers);
}
