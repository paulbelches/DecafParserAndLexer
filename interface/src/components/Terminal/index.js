
import React from "react"
import css from './terminal.css'

const  Terminal = (props) => {
    return( 
        <div class="terminal-window">
        <header>
            <div class="button green"></div>
            <div class="button yellow"></div>
            <div class="button red"></div>
        </header>
        <section class="terminal">
            <textarea 
                rows="39" 
                cols="91" 
                class="text" 
                value = {props.value}
                onChange={(event) => {props.setValue(event.target.value)}}
            />
        </section>
        </div>
    )
}
export default Terminal;
