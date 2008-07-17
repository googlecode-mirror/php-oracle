<?xml version="1.0" encoding="ISO-8859-1"?>
<!--
Author: William Candillon <wcandillon@php.net>, (http://wcandillon.blogspot.com/)
License: GPL (http://www.opensource.org/licenses/gpl-license.php)

This stylesheet generate a graph in dot format from an xml tree.
-->
<!DOCTYPE stylesheet [
    <!ENTITY xsl "http://www.w3.org/1999/XSL/Transform">
    <!ENTITY tab "    ">
    <!ENTITY newline "
">
    <!ENTITY indent "    ">
]>
<xsl:stylesheet version="1.0" xmlns="&xsl;" xmlns:xsl="&xsl;">
  <xsl:output method="text" indent="no"/>
    <xsl:template match="*">
        <xsl:if test="not(parent::*)">
          <xsl:text>digraph Parse_Tree {&newline;</xsl:text>
        </xsl:if>
        <xsl:if test="parent::*">
          <xsl:call-template name="generateRelation">
            <xsl:with-param name="parent" select="parent::*" />
            <xsl:with-param name="child" select="." />
          </xsl:call-template>
          <xsl:call-template name="generateLabel">
            <xsl:with-param name="node" select="." />
          </xsl:call-template>
        </xsl:if>

        <xsl:if test="normalize-space(text())!=''">
          <xsl:value-of select="generate-id()" />
          <xsl:text> -&gt; </xsl:text>
          <xsl:value-of select="@id" />
          <xsl:text>;&newline;&tab;</xsl:text>
          <xsl:value-of select="@id" />
          <xsl:text> [label="</xsl:text>
          <xsl:value-of select="translate(text(), '&#34;', ' ')" />
          <xsl:text>"];&newline;&tab;</xsl:text>
        </xsl:if>

        <xsl:for-each select="child::*">
          <xsl:call-template name="generateRelation">
            <xsl:with-param name="parent" select="parent::*" />
            <xsl:with-param name="child" select="." />
          </xsl:call-template>

          <xsl:call-template name="generateLabel">
            <xsl:with-param name="node" select="." />
          </xsl:call-template>

          <xsl:if test="parent::*[not(parent::*)]">
            <xsl:call-template name="generateLabel">
              <xsl:with-param name="node" select="parent::*" />
            </xsl:call-template>
          </xsl:if>

          <xsl:if test="normalize-space(text())!=''">
            <xsl:value-of select="generate-id()" />
            <xsl:text> -&gt; </xsl:text>
            <xsl:value-of select="@id" />
            <xsl:text>;&newline;&tab;</xsl:text>
            <xsl:value-of select="@id" />
            <xsl:text> [label="</xsl:text>
            <xsl:value-of select="translate(text(), '&#34;', ' ')" />
            <xsl:text>"];&newline;&tab;</xsl:text>
          </xsl:if>

          <xsl:apply-templates select="child::*"/>
        </xsl:for-each>
        <xsl:if test="not(parent::*)">
          <xsl:text>&newline;}</xsl:text>
        </xsl:if>
    </xsl:template>

    <xsl:template name="generateLabel">
      <xsl:param name="node"></xsl:param>
      <xsl:value-of select="generate-id($node)" />
      <xsl:text> [label="</xsl:text>
      <xsl:value-of select="local-name($node)" />
      <xsl:text>"];&newline;&tab;</xsl:text>
    </xsl:template>

    <xsl:template name="generateRelation">
      <xsl:param name="parent"></xsl:param>
      <xsl:param name="child"></xsl:param>
      <xsl:value-of select="generate-id($parent)" />
      <xsl:text> -&gt; </xsl:text>
      <xsl:value-of select="generate-id($child)" />
      <xsl:text>;&newline;&tab;</xsl:text>
    </xsl:template>
</xsl:stylesheet>