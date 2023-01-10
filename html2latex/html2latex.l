/* Name: Sarah Huang
 * Course: COSC 461
 * Program: html2latex.l
 * Purpose: Convert a subset of HTML into LaTeX.
 */


%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int list_type;
%}

%option       noyywrap nounput yylineno
%x            COMMENT PARA PRE OL UL LI

%%


"<h1>"[^<]*"</h1>" {
    /**************************************************************************
     * Matched an HTML H1 header so print it out as a LateX section title.
     * The beginning and ending tags need to be stripped off before the
     * title can be formatted in LateX.
     *************************************************************************/
    yytext[yyleng-5] = 0;
    printf( "\\section{%s}", yytext+4 );
}

"<h2>"[^<]*"</h2>" {
	/**************************************************************************
     * Matched an HTML H2 header so print it out as a LateX section title.
     * The beginning and ending tags need to be stripped off before the
     * title can be formatted in LateX.
     *************************************************************************/
	yytext[yyleng-5] = 0;
	printf( "\\subsection{%s}", yytext+4 );
}

"<h3>"[^<]*"</h3>" {
	/**************************************************************************
     * Matched an HTML H3 header so print it out as a LateX section title.
     * The beginning and ending tags need to be stripped off before the
     * title can be formatted in LateX.
     *************************************************************************/
	yytext[yyleng-5] = 0;
	printf( "\\subsubsection{%s}", yytext+4 );
}





[ \t\n\r]+ {
    /**************************************************************************
     * Matched some whitespace that is not inside of an HTML tag. We
     * just ignore the whitespace.
     *************************************************************************/
}

. {
    /**************************************************************************
     * Matched something that we did not expect to see. Issue an error and
     * exit the program with a failure code.
     *************************************************************************/
    fprintf( stderr, "Unexpected input at line %d: '%s'\n", yylineno, yytext );
    exit( 1 );
}





"<!--" {
	/**************************************************************************
	 * Matched an HTML comment so print it out as a LateX comment. The
	 * beginning and ending tags are stripped off before the LateX comment
     * is emitted.
	 *************************************************************************/
	printf( "%% " );
	BEGIN COMMENT;
}

<COMMENT>"-->" {
    /**************************************************************************
     * Matched an HTML end comment while parsing an HTML comment. Print out
     * a new line and resume normal parsing.
     *************************************************************************/
    printf( "\n" );
    BEGIN 0;
}

<COMMENT>[\n](\r)? {
    /**************************************************************************
     * Matched a newline while parsing an HTML comment. Print out a new
     * line making sure to mark the next line as a comment as well.
     *************************************************************************/
    printf( "\n%% " );
}

<COMMENT>[ \t] {
    /**************************************************************************
     * Matched some white space while parsing an HTML comment. Print out
     * the white space as is.
     *************************************************************************/
    printf( "%s", yytext );
}

<COMMENT>. {
    /**************************************************************************
     * Matched any other text while parsing an HTML comment. Print out
     * the text as is.
     *************************************************************************/
    printf( "%s", yytext );
}





"<pre>" {
	/**************************************************************************
     * Matches the tags for HTML pre-formatted paragraphs.
	 * All text between the beginning and ending tags should be 
	 * preserved exactly in the output.
     *************************************************************************/
	printf("\\begin{verbatim}");
	BEGIN PRE;
}

<PRE>"</pre>" {
	printf("\\end{verbatim}\n");
	BEGIN 0;
}

<PRE>[\n](\r)? {
	printf("\n");
}

<PRE>[ \t] {
	printf( "%s", yytext );
}

<PRE>. {
	printf( "%s", yytext );
}





"<p>" {
	/**************************************************************************
     * Matches the tags for HTML paragraphs and convert to LaTeX paragraphs.
     *************************************************************************/	
	BEGIN PARA;
}

<PARA>"</p>" {
	printf( "\n\n");
	BEGIN 0;
}

<PARA>"<small>"[^<]*"</small>" {
	/**************************************************************************
     * Matches the tags for HTML small text.
	 * Tags are stripped off before printing.
     *************************************************************************/
	yytext[yyleng-8] = 0;
	printf( "{\\scriptsize %s}", yytext+7 );
}

<PARA>"<big>"[^<]*"</big>" {
	/**************************************************************************
     * Matches the tags for HTML large text.
	 * Tags are stripped off before printing.
     *************************************************************************/
	yytext[yyleng-6] = 0;
	printf( "{\\Large %s}", yytext+5 );
}

<PARA>"<b>"[^<]*"</b>" {
	/**************************************************************************
     * Matches the tags for HTML bold text.
     * Tags are stripped off before printing.
     *************************************************************************/
	yytext[yyleng-4] = 0;
	printf( "\\textbf{%s}", yytext+3 );
}

<PARA>"<i>"[^<]*"</i>" {
	/**************************************************************************
     * Matches the tags for HTML italics text.
     * Tags are stripped off before printing.
     *************************************************************************/
	yytext[yyleng-4] = 0;
	printf( "\\textit{%s}", yytext+3 );
}

<PARA>"<strong>"[^<]*"</strong>" {
	/**************************************************************************
     * Matches the tags for HTML strong text.
     * Tags are stripped off before printing.
     *************************************************************************/
	yytext[yyleng-9] = 0;
	printf( "\\textmd{%s}", yytext+8 );
}

<PARA>"<em>"[^<]*"</em>" {
	/**************************************************************************
     * Matches the tags for HTML emphasized text.
     * Tags are stripped off before printing.
     *************************************************************************/
	yytext[yyleng-5] = 0;
	printf( "\\emph{%s}", yytext+4 );
}

<PARA>"<sup>"[^<]*"</sup>" {
	/**************************************************************************
     * Matches the tags for HTML superscript text.
     * Tags are stripped off before printing.
     *************************************************************************/
	yytext[yyleng-6] = 0;
	printf( "\\textsuperscript{%s}", yytext+5 );
}

<PARA>"<sub>"[^<]*"</sub>" {
	/**************************************************************************
     * Matches the tags for HTML subscript text.
     * Tags are stripped off before printing.
     *************************************************************************/
	yytext[yyleng-6] = 0;
	printf( "\\textsubscript{%s}", yytext+5 );
}

<PARA>[\n](\r)? {
	printf( "\n " );
}

<PARA>[ \t] {
	printf( "%s", yytext );
}

<PARA>. {
	printf( "%s", yytext );
}







"<ol>" {
	/*************************************************************************
     * Matches the tags for HTML ordered lists.
     *************************************************************************/
	list_type = 1;
	printf("\\begin{enumerate}");
	BEGIN OL;
}

<OL>"</ol>" {
	printf( "\\end{enumerate}\n");
	BEGIN 0;
}

<OL>"<li>" {
	/*************************************************************************
	* Matches the front tag for HTML list item.
	* Switches to list item environment.
	*************************************************************************/
	printf("\\item ");
	BEGIN LI;
}


<OL>[\n](\r)? {
	printf( "\n" );
}

<OL>[ \t] {
	printf( "%s", yytext );
}

<OL>. {
	printf( "%s", yytext );
}





"<ul>" {
	/*************************************************************************
     * Matches the tags for HTML unordered lists.
	*************************************************************************/
	list_type = 0;
	printf("\\begin{itemize}");
	BEGIN UL;
}

<UL>"</ul>" {
	printf( "\\end{itemize}\n");
	BEGIN 0;
}

<UL>"<li>" {
	/*************************************************************************
	* Matches the front tag for HTML ordered lists.
	* Switches to list item environment.
	*************************************************************************/
	 printf("\\item ");
	 BEGIN LI;
}

<UL>[\n](\r)? {
	printf( "\n" );
}

<UL>[ \t] {
	printf( "%s", yytext );
}

<UL>. {
	printf( "%s", yytext );
}





<LI>"</li>" {
	/*************************************************************************
     * Matches the back tag and text format tags for HTML list items.
	 * Switch back to the appropriate unordered/ordered list environment.
     *************************************************************************/
	printf("\n");
	if(list_type == 1)
		BEGIN OL;
	else if(list_type == 0)
		BEGIN UL;
}

<LI>"<small>"[^<]*"</small>" {
    yytext[yyleng-8] = 0;
	printf( "{\\scriptsize %s}", yytext+7 );
}

<LI>"<big>"[^<]*"</big>" {
	yytext[yyleng-6] = 0;
	printf( "{\\Large %s}", yytext+5 );
}

<LI>"<b>"[^<]*"</b>" {
	yytext[yyleng-4] = 0;
	printf( "\\textbf{%s}", yytext+3 );
}

<LI>"<i>"[^<]*"</i>" {
	yytext[yyleng-4] = 0;
	printf( "\\textit{%s}", yytext+3 );
}

<LI>"<strong>"[^<]*"</strong>" {
	yytext[yyleng-9] = 0;
	printf( "\\textmd{%s}", yytext+8 );
}

<LI>"<em>"[^<]*"</em>" {
	yytext[yyleng-5] = 0;
	printf( "\\emph{%s}", yytext+4 );
}

<LI>"<sup>"[^<]*"</sup>" {
	yytext[yyleng-6] = 0;
	printf( "\\textsuperscript{%s}", yytext+5 );
}

<LI>"<sub>"[^<]*"</sub>" {
	yytext[yyleng-6] = 0;
	printf( "\\textsubscript{%s}", yytext+5 );
}

<LI>[ \t] {
	printf( "%s", yytext );
}

<LI>. {
	printf( "%s", yytext );
}

%%

/**************************************************************************
* The main function for the HTML to LateX converter. Here we do three
* things:
 *  1. Print out the LateX document header.
 *  2. Invoke the lexer to print out the LateX document
 *  3. Print out the LateX footer.
 *************************************************************************/
int main( int argc, const char *argv[] ) {
    printf( "\\documentclass[12pt]{article}\n" );
    printf( "\\usepackage{fixltx2e}\n" );
    printf( "\n" );
    printf( "\\setlength{\\parindent}{0.0in}\n" );
    printf( "\\setlength{\\parskip}{0.125in}\n" );
    printf( "\n\n" );
    printf( "\\begin{document}\n" );
    yylex();
    printf( "\\end{document}\n" );
    return 0;
}
